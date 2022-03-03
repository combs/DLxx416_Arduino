# DLxx416_Arduino
Arduino library for the following OSRAM/Siemens intelligent displays:


DLX2416:

- DLR2416 (red)
- DLO2416 (high efficiency red)
- DLG2416 (green)


DLX3416:

- DLR3416 (red)
- DLO3416 (high efficiency red)
- DLG3416 (green)


## Usage (DLX2416):

```
#include "DLX2416.h"

// you can omit these pin definitions if they're the same as mine. 
// If you have wired up D0.. D6 on the display to Arduino pins 0-6 and are using an AVR, set usePortD to true for faster writes
// On other platforms usePortD should be false

// If you have bound the CE pins to high for a single display, just set the pin to something unimportant, like 12 below:

DLX2416 display(pinA0 = 8, pinA1 = 9, pinBL_AL = 12, pinCE1 = 12, pinCE2 = 12, pinCLR_AL = A2, pinCU_AL = A0, pinCUE = A3, pinD0 = 0, pinD1 = 1, pinD2 = 2, pinD3 = 3, pinD4 = 4, pinD5 = 5, pinD6 = 6, pinWR_AL = 7, usePortD = true);

...

display.begin();

// Call this once for each digit you want to update. From left to right, digits are 3... 0
// display.writeByte(display, digit_number, character);

display.writeByte(0, 3, "H");
display.writeByte(0, 2, "i");
display.writeByte(0, 1, "y");
display.writeByte(0, 0, "a");

// results: screen 0 is set to HIYA (Display only accepts uppercase; library translates)

// optionally, to release the pins...
display.end()

```

## Usage (DLX3416):

```
#include "DLX3416.h"

// you can omit these pin definitions if they're the same as mine. 
// If you have wired up D0.. D6 on the display to Arduino pins 0-6 and are using an AVR, set usePortD to true for faster writes
// On other platforms usePortD should be false

// If you have bound the CE pins to high for a single display, just set the pin to something unimportant, like 12 below:

DLX3416 display(pinA0 = 8, pinA1 = 9, pinBL_AL = 12, pinCE1 = 12, pinCE2 = 12, pinCE3_AL = 12, pinCE4_AL = 12, pinCLR_AL = A2, pinCU_AL = A0, pinCUE = A3, pinD0 = 0, pinD1 = 1, pinD2 = 2, pinD3 = 3, pinD4 = 4, pinD5 = 5, pinD6 = 6, pinWR_AL = 7, usePortD = true);

...

display.begin();

// Call this once for each digit you want to update. From left to right, digits are 3... 0
// display.writeByte(display, digit_number, character);

display.writeByte(0, 3, "H");
display.writeByte(0, 2, "i");
display.writeByte(0, 1, "y");
display.writeByte(0, 0, "a");

// results: screen 0 is set to Hiya

// optionally, to release the pins...
display.end()

```

## Not yet implemented

- Cursor functions
- Display full string (it's only a 4 char display so I've been doing this in my applications... PRs welcomed)
- Tell driver the number of displays and let it do smarter string handling 
- Port expanders (see [sumotoy/IntMatrixDisp](https://github.com/sumotoy/IntMatrixDisp))