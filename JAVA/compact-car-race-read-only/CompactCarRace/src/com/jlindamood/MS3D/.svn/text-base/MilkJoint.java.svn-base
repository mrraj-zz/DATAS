package com.jlindamood.MS3D;

import javax.media.j3d.Transform3D;
import javax.vecmath.Quat4f;
import javax.vecmath.Vector3f;

/**
 * Created by IntelliJ IDEA. Programmer: Jack Lindamood Date: Apr 18, 2004 Time: 5:52:37 PM
 */
public class MilkJoint
{
    String name;
    int parentIndex;
    // Quat4f localRefRotation=new Quat4f();
    // Vector3f localRefPosition=new Vector3f();
    Quat4f[] keyframeRot;
    Vector3f[] keyframePos;
    Transform3D inverseChainMatrix;
    Transform3D localRefMatrix = new Transform3D();

    void fillLocalAnimationMatrix()
    {
        processMe();
    }

    public String toString()
    {
        return "MilkJoint{" + ", name='" + name + '\'' + ", parentIndex=" + parentIndex + '}';
    }
    
    public Transform3D getLocalRefMatrix()
    {
        return localRefMatrix;
    }

    public void setLocalRefMatrix(Transform3D localRefMatrix)
    {
        this.localRefMatrix = localRefMatrix;
    }

    private void processMe()
    {
        // Interpolates missing rotations and positions
        {
            int maxKeyRot = keyframeRot.length - 1;
            while (maxKeyRot >= 0 && keyframeRot[maxKeyRot] == null)
                maxKeyRot--;

            int startIndex = 0;
            while (startIndex != maxKeyRot && startIndex < keyframeRot.length && keyframeRot[startIndex] == null)
            {
                startIndex++;
            }
            for (int i = 0; i < startIndex; i++)
            {
                keyframeRot[i] = new Quat4f();
            } // Set previous ones to nothing

            while (startIndex < maxKeyRot)
            {
                int next;
                for (next = startIndex + 1; next < maxKeyRot; next++)
                    if (keyframeRot[next] != null)
                        break;
                for (int k = startIndex + 1; k < next; k++)
                {
                    keyframeRot[k] = new Quat4f();
                    keyframeRot[k].interpolate(keyframeRot[startIndex], keyframeRot[next], ((float) k - startIndex - 1) / (next - startIndex));
                }
                startIndex = next;
            }
            for (int i = maxKeyRot + 1; i < keyframeRot.length; i++)
            {
                if (maxKeyRot >= keyframeRot.length)
                {
                    maxKeyRot = keyframeRot.length - 1;
                }
                if (maxKeyRot >= 0 && maxKeyRot < keyframeRot.length - 1)
                {
                    keyframeRot[i] = new Quat4f(keyframeRot[maxKeyRot]);
                }
            }
        }
        // Now fix positions
        {
            int maxKeyPos = keyframePos.length - 1;
            int startIndex;
            while (maxKeyPos >= 0 && keyframePos[maxKeyPos] == null)
                maxKeyPos--;

            startIndex = 0;
            while (startIndex != maxKeyPos && startIndex < keyframePos.length && keyframePos[startIndex] == null)
            {
                startIndex++;
            }
            for (int i = 0; i < startIndex; i++)
            {
                keyframePos[i] = new Vector3f();
            } // Set previous ones to nothing

            while (startIndex < maxKeyPos)
            {
                int next;
                for (next = startIndex + 1; next < maxKeyPos; next++)
                    if (keyframePos[next] != null)
                        break;
                for (int k = startIndex + 1; k < next; k++)
                {
                    keyframePos[k] = new Vector3f();
                    keyframePos[k].interpolate(keyframePos[startIndex], keyframePos[next], ((float) k - startIndex - 1) / (next - startIndex));
                }
                startIndex = next;
            }
            for (int i = maxKeyPos + 1; i < keyframePos.length; i++)
            {
                if (i >= 0 && i < keyframePos.length && maxKeyPos >= 0 && maxKeyPos < keyframePos.length)
                    keyframePos[i] = new Vector3f(keyframePos[maxKeyPos]);
            }
        }
    }
}