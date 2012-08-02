package com.jlindamood.MS3D;

import com.sun.j3d.utils.image.TextureLoader;

import javax.media.j3d.*;
import javax.vecmath.Color4f;
import java.io.FileNotFoundException;
import java.net.MalformedURLException;
import java.net.URL;

/**
 * Created by IntelliJ IDEA. Programmer: Jack Lindamood Date: Apr 17, 2004 Time:
 * 12:56:31 AM
 */

/*
 * typedef struct { char name[32]; // float ambient[4]; // float diffuse[4]; //
 * float specular[4]; // float emissive[4]; // float shininess; // 0.0f - 128.0f
 * float transparency; // 0.0f - 1.0f char mode; // 0, 1, 2 is unused now char
 * texture[128]; // texture.bmp char alphamap[128]; // alpha.bmp }
 * ms3d_material_t;
 */
class MilkshapeMaterial
{
    String name;

    Color4f ambColor;

    Color4f difColor;

    Color4f specColor;

    Color4f emisColor;

    float shininess;

    float transparency;

    String texture;

    String alphaMap;

    private Appearance myAppearance;

    // public void loadMaterials(BufferedReader file) throws
    // ParsingErrorException {
    // }

    private Material generateMaterial()
    {
        Material tempMaterial = new Material();
        tempMaterial.setAmbientColor(ambColor.x, ambColor.y, ambColor.z);
        tempMaterial.setEmissiveColor(emisColor.x, emisColor.y, emisColor.z);
        tempMaterial.setDiffuseColor(difColor.x, difColor.y, difColor.z);
        tempMaterial.setSpecularColor(specColor.x, specColor.y, specColor.z);
        tempMaterial.setShininess(shininess);
        return tempMaterial;
    }

    /*
     * private Texture generateTexture(String basePath) throws
     * FileNotFoundException { if (texture.length()==0) return null; if (!new
     * File(basePath+texture).exists()) throw new
     * FileNotFoundException("Couldn't find colormap file " + texture);
     * 
     * TextureLoader textureHelper=new TextureLoader(basePath+texture,null);
     * return textureHelper.getTexture(); }
     */
    private Texture generateTexture(URL baseURL) throws FileNotFoundException
    {
        if (texture.length() == 0)
            return null;

        texture = texture.replace('\\', '/');
        
        TextureLoader textureHelper = null;
        try
        {
            textureHelper = new TextureLoader(new URL(baseURL, texture), null);
        }
        catch (MalformedURLException e)
        {
            System.out.println("Shouldn't happen, error loading texture: " + texture);
        }
        if (textureHelper.getTexture() == null)
            throw new FileNotFoundException("Couldn't load texture: " + texture);
        return textureHelper.getTexture();
        // TODO: Support Alpha Maps
    }

    public Appearance getApperance(URL baseURL) throws FileNotFoundException
    {

        if (myAppearance != null)
            return myAppearance;
        myAppearance = new Appearance();
        myAppearance.setMaterial(generateMaterial());
        myAppearance.setTexture(null);
        myAppearance.setTexture(generateTexture(baseURL));

        TextureAttributes texAt = new TextureAttributes();
        texAt.setTextureMode(TextureAttributes.MODULATE);
        texAt.setTextureBlendColor(difColor.x, difColor.y, difColor.z, 1.0f - difColor.w);
        myAppearance.setTextureAttributes(texAt);

        RenderingAttributes RA = new RenderingAttributes();
        RA.setIgnoreVertexColors(true);
        myAppearance.setRenderingAttributes(RA);

        if (transparency != 1)
        {
            TransparencyAttributes transAtt = new TransparencyAttributes(TransparencyAttributes.BLENDED, 1 - transparency);
            myAppearance.setTransparencyAttributes(transAtt);
        }
        return myAppearance;
    }

    public String toString()
    {
        return "MilkshapeMaterial{" + "alphaMap='" + alphaMap + '\'' + ", texture='" + texture + '\'' + ", difColor=" + difColor + ", name='" + name + '\'' + '}';
    }
}