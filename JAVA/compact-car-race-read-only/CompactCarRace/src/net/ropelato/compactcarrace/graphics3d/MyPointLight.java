package net.ropelato.compactcarrace.graphics3d;
import javax.media.j3d.*;
import javax.vecmath.*;

/**
 * <p>�berschrift: SpeedUp</p>
 *
 * <p>Beschreibung: A simple race game in java</p>
 *
 * <p>Copyright: Copyright (c) 2006</p>
 *
 * <p>Organisation: ---</p>
 *
 * @author Sandro Ropelato
 * @version 1.0
 */

public class MyPointLight extends BranchGroup
{
    TransformGroup transformGroup;
    Transform3D transform3D = new Transform3D();
    PointLight pointLight;
    BoundingSphere bounds;

    public MyPointLight(Color3f color, BoundingSphere bounds)
    {
        this.bounds = bounds;

        transformGroup = new TransformGroup(transform3D);

        pointLight = new PointLight();
        pointLight.setColor(color);
        pointLight.setInfluencingBounds(bounds);
        transformGroup.addChild(pointLight);

        transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        addChild(transformGroup);
    }

    public void setPosition(float posX, float posY, float posZ)
    {
        transform3D.setTranslation(new Vector3f(posX, posY, posZ));
        transformGroup.setTransform(transform3D);
    }
}

