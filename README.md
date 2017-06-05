# teensyJoystick

** main operation code in teensyCode->magsensor.c **

A wireless magnetic joystick interpreted by a teensy 3.2

All code is contained on the Teensy 3.2. The teensy acts as a USB keyboard/mouse and sends commands according to the position of the joystick. Using the capacitive button on the backpack PCB, the key mapping of the teensy can be changed to the following

                
[ALPHA KEYS]    W      S       A        D

[ARROW KEYS]    up     down    left     right

[MOUSE CTRL]    up     down    left     right


The provided code can be changed to add different modes and map the joystick to different inputs

