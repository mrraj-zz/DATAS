package com.jlindamood.MS3D;

/**
 * Created by IntelliJ IDEA.
 * Date: Apr 16, 2004
 * Time: 11:17:30 PM
 *
 * @author Jack Lindamood
 */

import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.universe.SimpleUniverse;
import com.sun.j3d.utils.behaviors.vp.OrbitBehavior;
import com.sun.j3d.utils.behaviors.keyboard.KeyNavigatorBehavior;
import com.sun.j3d.utils.behaviors.sensor.SensorBeamEcho;
import com.sun.j3d.loaders.Scene;

import javax.media.j3d.*;
import javax.vecmath.*;
import java.applet.Applet;
import java.awt.*;
import java.io.*;
import java.net.URL;

public class MilkTester extends Applet
{

    private static final long serialVersionUID = -4345354147192126597L;
    private static final BoundingSphere INFINITE_SPHERE = new BoundingSphere(new Point3d(0, 0, 0), Double.MAX_VALUE);
    final static String FILE_NAME = "world/data/windengine1.ms3d";

    public BranchGroup createSceneGraph()
    {

        BranchGroup objRoot = new BranchGroup();
        final URL model = MilkTester.class.getClassLoader().getResource(FILE_NAME);
        MilkLoader ii = new MilkLoader();
        ii.setFlags(MilkLoader.LOAD_ALL);
        try
        {
            Scene s = ii.load(model);
            MilkAnimation animation = (MilkAnimation) s.getBehaviorNodes()[0];
            animation.setDuration(1000);
            animation.setSchedulingBounds(INFINITE_SPHERE);
            s.getSceneGroup().addChild(s.getBehaviorNodes()[0]);
            objRoot.addChild(s.getSceneGroup());

        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace(); // To change body of catch statement use File | Settings | File Templates.
        }

        DirectionalLight DL = new DirectionalLight(new Color3f(1, 1, 1), new Vector3f(0, 0, -1));
        DL.setInfluencingBounds(INFINITE_SPHERE);
        objRoot.addChild(DL);

        AmbientLight AL = new AmbientLight(new Color3f(Color.white));
        AL.setInfluencingBounds(INFINITE_SPHERE);
        objRoot.addChild(AL);

        drawAxis(objRoot);

        return objRoot;
    } // End of createSceneGraph

    private static void drawAxis(BranchGroup objRoot)
    {
        SensorBeamEcho beam = new SensorBeamEcho(new Point3d(1, 0, 0), .05, false);
        ColoringAttributes CA = new ColoringAttributes();
        CA.setColor(new Color3f(Color.yellow));
        beam.getAppearance().setColoringAttributes(CA);
        objRoot.addChild(beam);

        beam = new SensorBeamEcho(new Point3d(0, 1, 0), .05, false);
        CA = new ColoringAttributes();
        CA.setColor(new Color3f(Color.cyan));
        beam.getAppearance().setColoringAttributes(CA);
        objRoot.addChild(beam);

        beam = new SensorBeamEcho(new Point3d(0, 0, 1), .05, false);
        CA = new ColoringAttributes();
        CA.setColor(new Color3f(Color.pink));
        beam.getAppearance().setColoringAttributes(CA);
        objRoot.addChild(beam);

    }

    public void init()
    {
        setLayout(new BorderLayout());
        Canvas3D drawingBoard = new Canvas3D(SimpleUniverse.getPreferredConfiguration());

        add(drawingBoard);
        SimpleUniverse simpleU = new SimpleUniverse(drawingBoard);
        simpleU.getViewingPlatform().setNominalViewingTransform();
        simpleU.getViewer().getView().setFrontClipDistance(.01);

        BranchGroup scene = null;
        scene = createSceneGraph();

        KeyNavigatorBehavior keyBehave = new KeyNavigatorBehavior(drawingBoard, simpleU.getViewingPlatform().getViewPlatformTransform());
        keyBehave.setSchedulingBounds(INFINITE_SPHERE);
        scene.addChild(keyBehave);
        scene.compile();

        OrbitBehavior orbitBehave = new OrbitBehavior(drawingBoard);
        orbitBehave.setSchedulingBounds(new BoundingSphere(INFINITE_SPHERE));
        simpleU.getViewingPlatform().setViewPlatformBehavior(orbitBehave);

        simpleU.addBranchGraph(scene);
    }

    public MilkTester()
    {
    } // end of Constructor

    public static void main(String[] args)
    {
        final int FRAME_SIZE = 512;
        MainFrame app = new MainFrame(new MilkTester(), FRAME_SIZE, FRAME_SIZE);

        int xAlign = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth() - FRAME_SIZE;
        int yAlign = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight() - FRAME_SIZE;
        app.setLocation(xAlign / 2, yAlign / 2);
        app.setTitle(FILE_NAME);

    }
} // end of class
