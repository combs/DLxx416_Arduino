
#include "DL2416T.h"

// DL2416T display(pinA0 = 8, pinA1 = 9, pinBL_AL = 12, pinCE1 = 12, pinCE2 = 12, pinCLR_AL = A2, pinCU_AL = A0, pinCUE = A3, pinD0 = 0, pinD1 = 1, pinD2 = 2, pinD3 = 3, pinD4 = 4, pinD5 = 5, pinD6 = 6, pinWR_AL = 7, usePortD = true);

// you can omit these pin definitions if they're the same as the defaults. 
// If you have wired up D0.. D6 on the display to Arduino pins 0-6 and are using an AVR, set usePortD to true for faster writes
// On other platforms usePortD should be false

// If you have bound the CE pins to their "True" values (ce1 and ce2 GND) for a single display, just set the pin to something unimportant, like 12 below.

DL2416T display(/* A0  */ 8, 
                /* A1  */ 9, 
                /* BL  */ 12, 
                /* CE1 */ 12, 
                /* CE2 */ 12, 
                /* CLR */ A2, 
                /* CU  */ A0, 
                /* CUE */ A3, 
                /* D0  */ 0, 
                /* D1  */ 1, 
                /* D2  */ 2, 
                /* D3  */ 3, 
                /* D4  */ 4, 
                /* D5  */ 5, 
                /* D6  */ 6, 
                /* WR  */ 7, 
                /* usePortD */ true);
 
// If you are using the exact same pins as the defaults above, and usePortD, you can construct it with:
// DL2416T display();

void setup() {
  
    delay(1000);
    display.begin();

}

void loop() {

    display.clear();

    // Call this once for each digit you want to update. From left to right, digits are 3... 0
    // display.writeByte(display, digit_number, character);

    delay(500);
    display.writeByte(0, 3, 'H');
    delay(500);
    display.writeByte(0, 2, 'i');
    delay(500);
    display.writeByte(0, 1, 'y');
    delay(500);
    display.writeByte(0, 0, 'a');
    delay(5000);  

    // results: screen 0 is set to HIYA (Display only accepts uppercase; library translates)

    delay(5000);

    // optionally, to release the pins...
    // display.end()
 
}