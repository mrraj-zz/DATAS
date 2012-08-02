package com.jlindamood.MS3D;

import javax.media.j3d.*;
import javax.vecmath.Point3f;
import javax.vecmath.Quat4f;
import javax.vecmath.Vector3f;
import java.util.Enumeration;

/**
 * This behavior controlls the animation of Milkshape3D files.
 * 
 * @author Jack Lindamood
 */
public class MilkAnimation extends Behavior
{
    private SyncedGeometryUpdate toUpdate;

    private Quat4f unSyncbeginAngle = new Quat4f();
    private Vector3f unSyncbeginPos = new Vector3f();
    MilkFile movementFile;
    int startFrame;
    int endFrame;
    private int maxFrame;
    long duration;
    Transform3D[] jointMovements;
    Alpha changeTimer;
    WakeupCondition whenToWake;
    int currentFrame;
    float changeAmnt;
    Transform3D tempUnSyncd = new Transform3D();
    MilkJoint[] milkJoints;
    
    MilkAnimation(MilkFile movementFile, int startFrame, int endFrame, int duration)
    {
        this.maxFrame = endFrame;
        whenToWake = new WakeupOnElapsedFrames(5);
        
        milkJoints = movementFile.myJoints;

        this.setUserData("Exact MS aniamtion");
        this.movementFile = movementFile;
        this.startFrame = startFrame;
        this.endFrame = endFrame;
        this.duration = duration;
        jointMovements = new Transform3D[movementFile.nNumJoints];

        for (int i = 0; i < jointMovements.length; i++)
            jointMovements[i] = new Transform3D();

        changeTimer = new Alpha(1, duration);
        whenToWake = new WakeupOnElapsedFrames(0);
        toUpdate = new SyncedGeometryUpdate();
        this.setUserData("Exact Animation");
        this.setEnable(true);
    }
    
    public Transform3D[] getJointMovements()
    {
        return jointMovements;
    }

    public void initialize()
    {
        changeTimer.setStartTime(System.currentTimeMillis());
        this.wakeupOn(whenToWake);
        currentFrame = startFrame;
    }

    public void processStimulus(Enumeration enumeration)
    {
        if (changeTimer.finished())
        {
            changeTimer.setStartTime(System.currentTimeMillis());
            currentFrame++;
            if (currentFrame == endFrame)
                currentFrame = startFrame;
        }
        changeAmnt = changeTimer.value();
        // currentFrame=2;
        // changeAmnt=0;
        createJointTransforms(changeAmnt);

        /*
         * System.out.println("Keyframe: " + currentFrame); for (int i=0;i<movementFile.myJoints.length;i++) System.out.println(movementFile.myJoints[i].inverseChainMatrix); System.out.println("*****"); for (int i=0;i<jointMovements.length;i++) System.out.println(jointMovements[i]); System.out.println("DONE"); System.exit(0);
         */
        combineWithInverse();

        for (int i = 0; i < movementFile.nNumGroups; i++)
        {
            toUpdate.setMesh(movementFile.myGroups[i]);
            movementFile.myGroups[i].groupGeometry.updateData(toUpdate);
        }
        this.wakeupOn(whenToWake);
    }

    private void combineWithInverse()
    {
        for (int i = 0; i < jointMovements.length; i++)
        {
            jointMovements[i].mul(movementFile.myJoints[i].inverseChainMatrix);
        }
    }

    private void createJointTransforms(float changeAmnt)
    {
        for (int index = 0; index < jointMovements.length; index++)
        {
            int theParentIndex = movementFile.myJoints[index].parentIndex;

            unSyncbeginAngle.set(movementFile.myJoints[index].keyframeRot[currentFrame]);
            unSyncbeginPos.set(movementFile.myJoints[index].keyframePos[currentFrame]);

            unSyncbeginAngle.interpolate(movementFile.myJoints[index].keyframeRot[currentFrame + 1], changeAmnt);
            unSyncbeginPos.interpolate(movementFile.myJoints[index].keyframePos[currentFrame + 1], changeAmnt);
            tempUnSyncd.set(unSyncbeginAngle, unSyncbeginPos, 1);
            jointMovements[index].set(movementFile.myJoints[index].localRefMatrix);
            jointMovements[index].mul(tempUnSyncd);
            if (theParentIndex != -1)
            {
                tempUnSyncd.set(jointMovements[index]);
                jointMovements[index].set(jointMovements[theParentIndex]);
                jointMovements[index].mul(tempUnSyncd);
            }
        }
    }

    /**
     * Changes the time (in Milliseconds) from one keyframe to the next
     * 
     * @param duration
     *            new duration
     */
    public void setDuration(long duration)
    {
        this.duration = duration;
        changeTimer.setIncreasingAlphaDuration(duration);
    }

    /**
     * Returns the animation files current duration between frames
     * 
     * @return the animation file's duration
     */
    public long getDuration()
    {
        return this.duration;
    }
    
    public MilkJoint[] getMilkJoints()
    {
        return milkJoints;
    }

    public void setMilkJoints(MilkJoint[] milkJoints)
    {
        this.milkJoints = milkJoints;
    }

    /**
     * Sets the starting and ending frames for the animation to those given
     * 
     * @param start
     *            Starting frame
     * @param end
     *            Ending frame
     */
    public void setFrames(int start, int end)
    {
        if (start < 0 || start > end || end > maxFrame)
            return;
        startFrame = start;
        endFrame = end;
    }

    class SyncedGeometryUpdate implements GeometryUpdater
    {
        MilkshapeGroup updatingGroup;
        Point3f myCurPoint = new Point3f();
        Vector3f myCurNorm = new Vector3f();

        void setMesh(MilkshapeGroup toMesh)
        {
            updatingGroup = toMesh;
        }

        public void updateData(Geometry geometry)
        {

            int currentBoneIndex;
            for (int j = 0; j < updatingGroup.numTriangles; j++)
            {
                for (int s = 0; s < 3; s++)
                { // Each tri has 3 co-ords


                        int coordIndex = movementFile.myTri[updatingGroup.triangleIndices[j]].vertexIndices[s];
                        currentBoneIndex = movementFile.boneID[coordIndex];
                        myCurPoint.set(movementFile.vertexes[coordIndex]);
                        if (currentBoneIndex >= 0 && currentBoneIndex < jointMovements.length)
                        {
                            jointMovements[currentBoneIndex].transform(myCurPoint);
                        }
                        updatingGroup.myCurrentCoords[j * 9 + s * 3 + 0] = myCurPoint.x;
                        updatingGroup.myCurrentCoords[j * 9 + s * 3 + 1] = myCurPoint.y;
                        updatingGroup.myCurrentCoords[j * 9 + s * 3 + 2] = myCurPoint.z;

                        myCurNorm.set(movementFile.myTri[updatingGroup.triangleIndices[j]].vertexNormals[s]);
                        if (currentBoneIndex >= 0 && currentBoneIndex < jointMovements.length)
                        {
                            jointMovements[currentBoneIndex].transform(myCurNorm);
                        }
                        updatingGroup.myCurrentNorms[j * 9 + s * 3 + 0] = myCurNorm.x;
                        updatingGroup.myCurrentNorms[j * 9 + s * 3 + 1] = myCurNorm.y;
                        updatingGroup.myCurrentNorms[j * 9 + s * 3 + 2] = myCurNorm.z;
                }
            }
        }
    }
}