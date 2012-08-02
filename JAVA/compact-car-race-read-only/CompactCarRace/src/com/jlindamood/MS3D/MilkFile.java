package com.jlindamood.MS3D;

import com.sun.j3d.loaders.IncorrectFormatException;
import com.sun.j3d.loaders.ParsingErrorException;

import javax.media.j3d.Appearance;
import javax.media.j3d.Shape3D;
import javax.media.j3d.Transform3D;
import javax.vecmath.Color4f;
import javax.vecmath.Quat4f;
import javax.vecmath.Vector3d;
import javax.vecmath.Vector3f;
import java.io.DataInput;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;


/**
 * Created by IntelliJ IDEA.
  * Started Date: Apr 28, 2004
 *
 * @author Jack Lindamood
 */
class MilkFile {
    private DataInput file;
    private int nNumVertices;
    MilkshapeTriangle[] myTri;
    private int nNumTriangles;
    byte[] boneID;
    float[][] vertexes;
    private int[] vertexIndextoGroup;
    int nNumGroups;
    MilkshapeGroup[] myGroups;
    private int nNumMaterials;
    private MilkshapeMaterial[] myMats;
    int iTotalFrames;
    int nNumJoints;
    MilkJoint[] myJoints;
    private long loadTime;
    private static final boolean debug=false;
    private URL baseURL;


    private void invertWithParents() {
        for (int i=0;i<nNumJoints;i++){
            myJoints[i].inverseChainMatrix=new Transform3D(myJoints[i].localRefMatrix);
            myJoints[i].inverseChainMatrix.invert(myJoints[i].localRefMatrix);
//            myJoints[i].inverseChainMatrix.invertRotTrans();
            if (myJoints[i].parentIndex!=-1)
                myJoints[i].inverseChainMatrix.mul(myJoints[myJoints[i].parentIndex].inverseChainMatrix);
        }
    }

    private MilkFile(){ // used to create copies
    }

    MilkFile(URL baseURL,DataInput file) {
        this.file=file;
        this.baseURL=baseURL;

        loadInfo();
        processFile();
    }


    private void processFile() {


        for (int i=0;i<nNumGroups;i++)
            myGroups[i].buildGeo(myTri,vertexes);

        for (int i=0;i<nNumJoints;i++)
            myJoints[i].fillLocalAnimationMatrix();

        invertWithParents();
    }

    private void loadInfo() {
        loadTime=System.currentTimeMillis();
        try {
            loadHeader();
            if (debug) System.out.println("Time after loading header is " + (System.currentTimeMillis()-loadTime));
            loadVertexes();
            if (debug) System.out.println("Time after loading Vertexes is " + (System.currentTimeMillis()-loadTime));
            loadTriangles();
            if (debug) System.out.println("Time after loading Triangles is " + (System.currentTimeMillis()-loadTime));
            loadGroups();
            if (debug) System.out.println("Time after loading Groups is " + (System.currentTimeMillis()-loadTime));
            loadMaterials();
            if (debug) System.out.println("Time after loading Materials is " + (System.currentTimeMillis()-loadTime));
            loadFrames();
            // Should be done loading file here
        } catch (IOException e) {
            throw new ParsingErrorException("File blocked while loading" + e.getMessage());
        }
    }

    private void loadFrames() throws IOException {
        float multiplier=file.readFloat();
        file.readFloat();   // Current Time ignored
        iTotalFrames=file.readInt();
        nNumJoints=file.readUnsignedShort();
        byte[] inName=new byte[32];
        myJoints=new MilkJoint[nNumJoints];
        Transform3D converter=new Transform3D();
        Vector3d eulerVec=new Vector3d();
        Vector3d translation=new Vector3d();

        for (int i=0;i<nNumJoints;i++){
            myJoints[i]=new MilkJoint();
            myJoints[i].keyframeRot=new Quat4f[iTotalFrames];
            myJoints[i].keyframePos=new Vector3f[iTotalFrames];

            file.readByte();    //flags
            file.readFully(inName);
            myJoints[i].name = cutAtNull(inName);

            file.readFully(inName);
            String compare=cutAtNull(inName);

            myJoints[i].parentIndex=-1;
            for (int j=0;j<i;j++)
                if (myJoints[j].name.equals(compare)) myJoints[i].parentIndex=j;

            eulerVec.set(file.readFloat(),file.readFloat(),file.readFloat());
            translation.set(file.readFloat(),file.readFloat(),file.readFloat());
            myJoints[i].localRefMatrix.setEuler(eulerVec);
            myJoints[i].localRefMatrix.setTranslation(translation);
            int numRot=file.readUnsignedShort();
            int numPos=file.readUnsignedShort();
            int myTime;
            for (int j=0;j<numRot;j++){
                float letsSee=file.readFloat();
                myTime=(int)(multiplier*letsSee-1);
                eulerVec.set(file.readFloat(),file.readFloat(),file.readFloat());
                converter.setEuler(eulerVec);
                myJoints[i].keyframeRot[myTime]=new Quat4f();
//                myJoints[i].keyframeRot[myTime].set(converter.rot);
                converter.get(myJoints[i].keyframeRot[myTime]);
            }
            for (int j=0;j<numPos;j++){
                myTime=(int)(multiplier*file.readFloat()-1);
                myJoints[i].keyframePos[myTime]=new Vector3f(
                        file.readFloat(),
                        file.readFloat(),
                        file.readFloat()
                );
            }
        }
    }

    private void loadMaterials() throws IOException {
        nNumMaterials=file.readUnsignedShort();
        myMats=new MilkshapeMaterial[nNumMaterials];
        byte[] inString=new byte[128];
        for (int i=0;i<nNumMaterials;i++){
            myMats[i]=new MilkshapeMaterial();
            file.readFully(inString,0,32);
            myMats[i].name=cutAtNull(inString);
            myMats[i].ambColor=new Color4f(
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat()
                    );
            myMats[i].difColor=new Color4f(
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat()
                    );
            myMats[i].specColor=new Color4f(
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat()
                    );
            myMats[i].emisColor=new Color4f(
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat(),
                    file.readFloat()
                    );
            myMats[i].shininess=file.readFloat();
            myMats[i].transparency=file.readFloat();
            file.readByte();    // Unknown mode flag
            file.readFully(inString);
            myMats[i].texture=cutAtNull(inString);
            file.readFully(inString);
            myMats[i].alphaMap=cutAtNull(inString);
        }

    }

    private static String cutAtNull(byte[] inString) {
        for (int i=0;i<inString.length;i++)
            if (inString[i]==0) return new String(inString,0,i);
        return new String(inString);
    }

    private void loadGroups() throws IOException {
        nNumGroups=file.readUnsignedShort();
        myGroups=new MilkshapeGroup[nNumGroups];
        byte[] inName=new byte[32];
        for (int i=0;i<nNumGroups;i++){
            myGroups[i]=new MilkshapeGroup();
            file.readByte();
            file.readFully(inName);
            myGroups[i].name=cutAtNull(inName);
            myGroups[i].numTriangles=file.readUnsignedShort();
            myGroups[i].triangleIndices=new int[myGroups[i].numTriangles];
            for (int j=0;j<myGroups[i].numTriangles;j++){
                myGroups[i].triangleIndices[j]=file.readUnsignedShort();
            }
            myGroups[i].materialIndex=file.readByte();
        }
    }

    private void loadTriangles() throws IOException {
        nNumTriangles=file.readUnsignedShort();
        myTri=new MilkshapeTriangle[nNumTriangles];
        vertexIndextoGroup=new int[nNumTriangles];

        for (int i=0;i<nNumTriangles;i++){
            myTri[i]=new MilkshapeTriangle();
            file.readUnsignedShort(); // flags
            myTri[i].vertexIndices[0]=file.readUnsignedShort();
            myTri[i].vertexIndices[1]=file.readUnsignedShort();
            myTri[i].vertexIndices[2]=file.readUnsignedShort();
            for (int j=0;j<3;j++)
                for (int k=0;k<3;k++)
                    myTri[i].vertexNormals[j][k]=file.readFloat();
            for (int j=0;j<3;j++)
                myTri[i].texCoords[j][0]=file.readFloat();
            for (int j=0;j<3;j++)
                myTri[i].texCoords[j][1]=1-file.readFloat();
            file.readUnsignedByte(); // Smoothing group
            vertexIndextoGroup[i]=file.readUnsignedByte();
        }
    }

    private void loadVertexes() throws IOException{
        nNumVertices=file.readUnsignedShort();
        vertexes=new float[nNumVertices][];
        boneID=new byte[nNumVertices];

        for (int i=0;i<nNumVertices;i++){
            file.readByte();
            vertexes[i]=new float[]{
                file.readFloat(),
                file.readFloat(),
                file.readFloat()
            };
            boneID[i]=file.readByte();
            file.readUnsignedByte();   // unknown use
        }

    }

    private void loadHeader() throws IOException {
        byte [] b=new byte[10];
        file.readFully(b);
        if (!new String(b).equals("MS3D000000")) throw new IncorrectFormatException("Not MS format");
        if (file.readInt()!=4) throw new IncorrectFormatException("I only know milkshape format 4");
    }

    Shape3D makeShape(int i) throws FileNotFoundException {
        Shape3D myShape=new Shape3D();
        myShape.setGeometry(myGroups[i].groupGeometry);
        if (debug) System.out.println("Time after making geometry " + (System.currentTimeMillis()-loadTime));
        if (myGroups[i].materialIndex!=-1){
            Appearance a=myMats[myGroups[i].materialIndex].getApperance(baseURL);
            if (debug) System.out.println("Time after getting appearance " + (System.currentTimeMillis()-loadTime));
            myShape.setAppearance(a);
            if (debug) System.out.println("Time after setting appearance " + (System.currentTimeMillis()-loadTime));
        }
        myShape.setUserData(myGroups[i].name);
        return myShape;
    }

    public MilkFile spawnCopy() {
        MilkFile toReturn=new MilkFile();
        toReturn.file=null;
        toReturn.nNumVertices=this.nNumVertices;
        toReturn.myTri=this.myTri;
        toReturn.nNumTriangles=this.nNumTriangles;
        toReturn.boneID=this.boneID;
        toReturn.vertexes=this.vertexes;
        toReturn.vertexIndextoGroup=this.vertexIndextoGroup;
        toReturn.nNumMaterials=this.nNumMaterials;
        toReturn.myMats=this.myMats;
        toReturn.iTotalFrames=this.iTotalFrames;
        toReturn.nNumJoints=this.nNumJoints;
        toReturn.myJoints=this.myJoints;
        toReturn.loadTime=0;

        toReturn.nNumGroups=this.nNumGroups;

//        toReturn.myGroups != this.myGroups; // Groups are diffrent!!
        toReturn.myGroups=new MilkshapeGroup[nNumGroups];
        for (int i=0;i<toReturn.nNumGroups;i++){
            toReturn.myGroups[i]=this.myGroups[i].spawn();
            toReturn.myGroups[i].buildGeo(toReturn.myTri,toReturn.vertexes);
        }
        return toReturn;
    }
}