package com.jlindamood.MS3D;

import com.jlindamood.MS3D.MilkAnimation;
import com.jlindamood.MS3D.MilkFile;
import com.sun.j3d.loaders.*;

import javax.media.j3d.Behavior;
import javax.media.j3d.BranchGroup;
import javax.media.j3d.Shape3D;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Reader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ConcurrentModificationException;

/**
 * MilkLoader extends LoaderBase for a standard loader class to place Milkshape .ms3d files into Java3d Scene graphs. Loaded objects are returned as a SceneBase which users can pull animation objects from. If loading textures gives you problems, just set the base URL with .setBaseURL() to the texture base directory and try then.
 * 
 * @author Jack Lindamood
 * @version 1.0
 * @see SceneBase
 */
public class MilkLoader extends LoaderBase
{

    private long loadTime;

    private boolean DEBUG = false;
    private MilkFile lastLoad;

    /**
     * Private helper method to create a MilkScene from a MilkFile
     * 
     * @param myFile
     *            MilkFile to create a scene from
     * @return Scene created from the file
     * @see Scene
     */
    private SceneBase createScene(MilkFile myFile) throws FileNotFoundException
    {
        SceneBase myScene = new SceneBase();
        loadTime = System.currentTimeMillis();
        BranchGroup sceneGroup = new BranchGroup();
        for (int i = 0; i < myFile.nNumGroups; i++)
        {
            if (DEBUG)
                System.out.println("Starting to process Shape" + i);
            Shape3D madeShape = myFile.makeShape(i);
            myScene.addNamedObject((String) madeShape.getUserData(), madeShape);
            sceneGroup.addChild(madeShape);
            if (DEBUG)
                System.out.println("Time after processing Shape" + i + " is " + (System.currentTimeMillis() - loadTime));
        }

        if ((loadFlags & LOAD_BEHAVIOR_NODES) != 0)
        {
            Behavior myActions;
            myActions = new MilkAnimation(myFile, 0, myFile.iTotalFrames - 1, 200);
            myScene.addBehaviorNode(myActions);
        }

        if (DEBUG)
            System.out.println("Time after processing Behavior is " + (System.currentTimeMillis() - loadTime));
        myScene.setSceneGroup(sceneGroup);
        return myScene;
    }

    /**
     * Produces a copy of the last file loaded. More efficient than reloaded a file because initial processing is completed and no file needs to be opened
     * 
     * @return a new MilkScene by spawning the last loaded file, or null no preivous file was loaded
     * @see Scene
     */
    public SceneBase spawnFile()
    {
        if (lastLoad == null)
            return null;
        try
        {
            return createScene(lastLoad.spawnCopy());
        }
        catch (FileNotFoundException e)
        {
            throw new ConcurrentModificationException("lastLoad was modified: " + e.getMessage());
        }
    }

    /**
     * Loads a MilkShape file from the path in the string s. All texture/alpha maps associated with the file are by default in the same directory as the .ms3d file specified. Texture directory can be changed by a call to setBasePath(String), allowing the programmer to seperate storage of model files and pictures.
     * 
     * @param s
     *            Filename
     * @return MilkScene loaded from the file
     * @throws FileNotFoundException
     *             Either .ms3d file or texture files don't exist
     * @throws IncorrectFormatException
     *             File doesn't check with MS3D header
     * @throws ParsingErrorException
     *             Some type of error while reading in file information
     * @see Scene
     */
    public Scene load(String s) throws FileNotFoundException, IncorrectFormatException, ParsingErrorException
    {
        try
        {
            return load(new File(s).toURI().toURL());
        }
        catch (MalformedURLException e)
        {
            throw new FileNotFoundException("Couldn't find file in load(String): " + e.getMessage());
        }
    }

    /**
     * Loads a MilkShape file from the path in the URL. All texture/alpha maps associated with the URL are by default in the same directory as the .ms3d file specified. Texture directory can be changed by a call to setBaseURL(URL), allowing the programmer to seperate storage of model files and pictures.
     * 
     * @param url
     *            Location of .ms3d file
     * @return MilkScene loaded from the file
     * @throws FileNotFoundException
     *             Either .ms3d file or texture files don't exist
     * @throws IncorrectFormatException
     *             File doesn't check with MS3D header
     * @throws ParsingErrorException
     *             Some type of error while reading in file information
     * @see Scene
     */
    public Scene load(URL url) throws FileNotFoundException, IncorrectFormatException, ParsingErrorException
    {
        if (baseUrl == null)
        {
            try
            {
                baseUrl = new URL(url.getProtocol(), url.getHost(), url.getPort(), new File(url.getPath()).getParent() + '/');
            }
            catch (MalformedURLException e)
            {
                throw new FileNotFoundException("Something wierd in load(URL): " + e.getMessage());
            }
        }
        try
        {
            LittleEndien file = new LittleEndien(url.openStream());
            lastLoad = new MilkFile(baseUrl, file);
            file.close();
        }
        catch (IOException e)
        {
            throw new FileNotFoundException(e.getMessage());
        }
        return createScene(lastLoad);
    }

    /**
     * Unsupported loading from a Reader. Allways throws ParsingErrorException
     * 
     * @param reader
     *            Unused
     * @return never reached
     * @throws FileNotFoundException
     *             For compatability w/ interface Loader
     * @throws IncorrectFormatException
     *             For compatability w/ interface Loader
     * @throws ParsingErrorException
     *             Allways thrown
     * @deprecated use load(String) load(URL)
     */
    public Scene load(Reader reader) throws FileNotFoundException, IncorrectFormatException, ParsingErrorException
    {
        throw new ParsingErrorException("load(reader) unsupported");
    }
}