package net.ropelato.compactcarrace.controls;

import javax.media.j3d.Canvas3D;

//import com.centralnexus.input.Joystick;

public class Controller
{
    Canvas3D canvas3D = null;
    int indexMax = 0;

    String[] commandName = new String[1000];
    int[] inputType = new int[1000];
    int[] inputSource = new int[1000];
    float[] inputShift = new float[1000];
    float[] inputScale = new float[1000];
    boolean[] inputInverse = new boolean[1000];
    boolean[] inputLocked = new boolean[1000];
    boolean[] oneHit = new boolean[1000];
    float[] smooth = new float[1000];
    float[] oldValue = new float[1000];

    KeyboardListener keyboardListener = null;

    // Joystick joystick = null;
    // MyJoystickListener myJoystickListener = null;
    boolean joystickAvailable = false;

    public static int KEYBOARD = 0;
    public static int JOYSTICK_BUTTON = 1;
    public static int JOYSTICK_AXIS = 2;
    public static int JOYSTICK_POV = 3;

    public static int X_AXIS = 0;
    public static int Y_AXIS = 1;
    public static int Z_AXIS = 2;
    public static int R_AXIS = 3;
    public static int U_AXIS = 4;
    public static int V_AXIS = 5;

    public Controller(Canvas3D canvas3D)
    {
        this.canvas3D = canvas3D;
        keyboardListener = new KeyboardListener();
        canvas3D.addKeyListener(keyboardListener);

        for (int i = 0; i < 1000; i++)
        {
            commandName[i] = "";
            inputType[i] = 0;
            inputSource[i] = 0;
            inputInverse[i] = false;
            inputLocked[i] = false;
            oneHit[i] = false;
        }

        /*
         * int joystickID = -1; try { for (int i = 0; i < Joystick.getNumDevices(); i++) { if (Joystick.isPluggedIn(i)) { joystick = Joystick.createInstance(i); joystickID = i; joystickAvailable = true; } } } catch (Exception e) { e.printStackTrace(); } if (joystickID >= 0) { myJoystickListener = new MyJoystickListener(); joystick.addJoystickListener(myJoystickListener); }
         */
    }

    /*
     * public void addCommand(String name, int inputType, int inputSource) { this.commandName[indexMax] = name; this.inputType[indexMax] = inputType; this.inputSource[indexMax] = inputSource; this.inputShift[indexMax] = 0f; this.inputScale[indexMax] = 1f; this.inputInverse[indexMax] = false; indexMax++; }
     */

    /*
     * public void addCommand(String name, int inputType, int inputSource, boolean oneHit) { this.commandName[indexMax] = name; this.inputType[indexMax] = inputType; this.inputSource[indexMax] = inputSource; this.inputShift[indexMax] = 0f; this.inputScale[indexMax] = 1f; this.oneHit[indexMax] = oneHit; this.inputInverse[indexMax] = false; indexMax++; }
     */

    public void addCommand(String name, int inputType, int inputSource, float shift, float scale, boolean inverse, float smooth, boolean oneHit)
    {
        this.commandName[indexMax] = name;
        this.inputType[indexMax] = inputType;
        this.inputSource[indexMax] = inputSource;
        this.inputShift[indexMax] = shift;
        this.inputScale[indexMax] = scale;
        this.inputInverse[indexMax] = inverse;
        this.smooth[indexMax] = smooth;
        this.oldValue[indexMax] = 0f;
        this.oneHit[indexMax] = oneHit;
        indexMax++;
    }

    public float getCommand(String name)
    {
        float value = 0f;
        float newValue = 0f;

        for (int i = 0; i < indexMax; i++)
        {
            if (commandName[i].equals(name))
            {
                if (inputType[i] == KEYBOARD)
                {
                    if (!oneHit[i])
                    {
                        if (keyboardListener.getKeyDown(inputSource[i]) == true)
                        {
                            newValue = 1f;
                        }
                        else
                        {
                            newValue = 0f;
                        }
                    }
                    else
                    {
                        if (inputLocked[i])
                        {
                            newValue = 0f;
                            if (keyboardListener.getKeyDown(inputSource[i]) == false)
                            {
                                inputLocked[i] = false;
                            }
                        }
                        else
                        {
                            if (keyboardListener.getKeyDown(inputSource[i]) == true)
                            {
                                newValue = 1f;
                                inputLocked[i] = true;
                            }
                        }
                    }
                }
                /*
                 * if (inputType[i] == JOYSTICK_BUTTON) { if (!oneHit[i]) { if (myJoystickListener.getJoystickButton(inputSource[i]) == true) { value = 1f; } else { value = 0f; } } else { if (inputLocked[i]) { value = 0f; if (myJoystickListener.getJoystickButton(inputSource[i]) == false) { inputLocked[i] = false; } } else { if (myJoystickListener.getJoystickButton(inputSource[i]) == true) { value = 1f; inputLocked[i] = true; } } } } if (inputType[i] == JOYSTICK_AXIS) { if (inputSource[i] == X_AXIS) { value = myJoystickListener.getJoystickAxisX(); } if (inputSource[i] == Y_AXIS) { value = myJoystickListener.getJoystickAxisY(); } if (inputSource[i] == Z_AXIS) { value = myJoystickListener.getJoystickAxisZ(); } if (inputSource[i] == R_AXIS) { value = myJoystickListener.getJoystickAxisR(); } if (inputSource[i] == U_AXIS) { value = myJoystickListener.getJoystickAxisU(); } if (inputSource[i] == V_AXIS) { value = myJoystickListener.getJoystickAxisV(); } value += inputShift[i]; value *= inputScale[i]; if (inputInverse[i]) { value = 1 - value; } } if (inputType[i] == JOYSTICK_POV) { value = myJoystickListener.getJoystickPOV(); value += inputShift[i]; value *= inputScale[i]; if (inputInverse[i]) { value = 1 - value; } }
                 */

                value = (oldValue[i] * smooth[i] + newValue) / (1 + smooth[i]);
                oldValue[i] = value;
            }

        }

        return value;
    }

    public void printJoystickAxis()
    {
        // myJoystickListener.printAxis();
    }

    public void printJoystickButtons()
    {
        // myJoystickListener.printButtons();
    }

}
