package com.jlindamood.MS3D;

import javax.media.j3d.TriangleArray;


/**
 * Created by IntelliJ IDEA.
 * Programmer: Jack Lindamood
 * Date: Apr 16, 2004
 * Time: 11:54:12 PM
 */

/*
typedef struct
{
    byte            flags;                              // SELECTED | HIDDEN
    char            name[32];                           //
    word            numtriangles;                       //
    word            triangleIndices[numtriangles];      // the groups group the triangles
    char            materialIndex;                      // -1 = no material
} ms3d_group_t;
*/
class MilkshapeGroup {
    String name;
    int numTriangles;
    int[] triangleIndices;
    byte materialIndex;
    TriangleArray groupGeometry;
    float[] myCurrentNorms;
    float[] myCurrentCoords;
    private float[] myCurrentTexCor;

    public String toString() {
        return "MilkshapeGroup{" +
                "name='" + name + '\'' +
                ", numTriangles=" + numTriangles +
                ", triangleIndices=" + triangleIndices +
                ", materialIndex=" + materialIndex +
                '}';
    }

    public void buildGeo(MilkshapeTriangle[] selectableTriangles,float[][] indexedVertexes) {
        if (numTriangles==0){
            groupGeometry=null;
            return;
        }
        TriangleArray tempGeometry=new TriangleArray(numTriangles*3,TriangleArray.COORDINATES | TriangleArray.NORMALS |
                 TriangleArray.TEXTURE_COORDINATE_2);

        myCurrentNorms=new float[numTriangles*3*3];
        myCurrentCoords=new float[numTriangles*3*3];
        myCurrentTexCor=new float[numTriangles*3*2];


        //TODO: Take away need for tempGeometry
        for (int i=0;i<numTriangles;i++){
            for (int j=0;j<3;j++){
                tempGeometry.setNormal(i*3+j,selectableTriangles[triangleIndices[i]].vertexNormals[j]);      // Jth Point normal
                tempGeometry.setCoordinate(i*3+j,indexedVertexes[selectableTriangles[triangleIndices[i]].vertexIndices[j]]);      // Jth Point Coord
                tempGeometry.setTextureCoordinate(0,i*3+j,selectableTriangles[triangleIndices[i]].texCoords[j]);    // Jth Tex Coord
            }
        }
        groupGeometry=new TriangleArray(numTriangles*3,TriangleArray.COORDINATES | TriangleArray.NORMALS |
                 TriangleArray.TEXTURE_COORDINATE_2 | TriangleArray.BY_REFERENCE);

        tempGeometry.getNormals(0,myCurrentNorms);
        groupGeometry.setNormalRefFloat(myCurrentNorms);

        tempGeometry.getCoordinates(0,myCurrentCoords);

        groupGeometry.setCoordRefFloat(myCurrentCoords);


        tempGeometry.getTextureCoordinates(0,0,myCurrentTexCor);
        groupGeometry.setTexCoordRefFloat(0,myCurrentTexCor);

        tempGeometry=null;

        groupGeometry.setCapability(TriangleArray.ALLOW_REF_DATA_WRITE);
        groupGeometry.setCapability(TriangleArray.ALLOW_REF_DATA_READ);
    }

    public MilkshapeGroup spawn() {
        MilkshapeGroup toReturn=new MilkshapeGroup();
        toReturn.name=this.name;
        toReturn.numTriangles=this.numTriangles;
        toReturn.triangleIndices=this.triangleIndices;
        toReturn.materialIndex=this.materialIndex;
        return toReturn;
    }

}