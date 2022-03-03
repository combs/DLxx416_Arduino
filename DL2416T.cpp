
#include "Arduino.h"
#include <stdint.h>
#include "Print.h"

#include "DL2416T.h"

DL2416T::DL2416T(uint8_t pinA0, uint8_t pinA1, uint8_t pinBL_AL, uint8_t pinCE1_AL, uint8_t pinCE2_AL, uint8_t pinCLR_AL, uint8_t pinCU_AL, uint8_t pinCUE, uint8_t pinD0, uint8_t pinD1, uint8_t pinD2, uint8_t pinD3, uint8_t pinD4, uint8_t pinD5, uint8_t pinD6, uint8_t pinWR_AL, uint8_t usePortD) {

    PIN_ADDRESS0 = pinA0;
    PIN_ADDRESS1 = pinA1;
    PIN_BL_AL = pinBL_AL;
    PIN_CE1_AL = pinCE1_AL; 
    PIN_CE2_AL = pinCE2_AL;
    PIN_CLR_AL = pinCLR_AL;
    PIN_CU_AL = pinCU_AL;
    PIN_CUE = pinCUE;
    PIN_D0 = pinD0;
    PIN_D1 = pinD1;
    PIN_D2 = pinD2;
    PIN_D3 = pinD3;
    PIN_D4 = pinD4;
    PIN_D5 = pinD5;
    PIN_D6 = pinD6;
    PIN_WR_AL = pinWR_AL;
    D_USE_PORTD = usePortD;
    
}

void DL2416T::begin() {
    
    pinMode(PIN_ADDRESS0, OUTPUT);
    pinMode(PIN_ADDRESS1, OUTPUT);
    pinMode(PIN_BL_AL, OUTPUT);
    pinMode(PIN_CE1_AL, OUTPUT);
    pinMode(PIN_CE2_AL, OUTPUT);
    pinMode(PIN_CLR_AL, OUTPUT);
    pinMode(PIN_CU_AL, OUTPUT);
    pinMode(PIN_CUE, OUTPUT);
    pinMode(PIN_WR_AL, OUTPUT);

    if (D_USE_PORTD) {
        DDRD = B11111111;
        set_portd(B00000000);
    } else {
        pinMode(PIN_D0, OUTPUT);
        pinMode(PIN_D1, OUTPUT);
        pinMode(PIN_D2, OUTPUT);
        pinMode(PIN_D3, OUTPUT);
        pinMode(PIN_D4, OUTPUT);
        pinMode(PIN_D5, OUTPUT);
        pinMode(PIN_D6, OUTPUT);
    }

    digitalWrite(PIN_ADDRESS0, HIGH);
    digitalWrite(PIN_ADDRESS1, HIGH);
    digitalWrite(PIN_BL_AL, HIGH);
    digitalWrite(PIN_CE1_AL, HIGH);
    digitalWrite(PIN_CE2_AL, HIGH);
    digitalWrite(PIN_CLR_AL, HIGH);
    digitalWrite(PIN_CU_AL, HIGH);
    digitalWrite(PIN_CUE, LOW);
    digitalWrite(PIN_WR_AL, HIGH);
    
}

void DL2416T::set_portd(uint8_t theByte) {

    uint8_t bit7 = PORTD & B10000000; // save current bit 7
    theByte = theByte & B01111111; // wipe bit 7 in new val
    PORTD = theByte | bit7; // write new vals

}

void DL2416T::writeByte(uint8_t display, uint8_t address, uint8_t theByte) {

    digitalWrite(PIN_ADDRESS0, address & 1);
    digitalWrite(PIN_ADDRESS1, (address >> 1) & 1);

    delayMicroseconds(DL2416T_DELAY_US);

    // DL2416T does not support lowercase letters

    if (theByte == '|') {
        theByte = '1';
    } else if (theByte == '`') {
        theByte = '\'';
    } else if (theByte == '~') {
        theByte = '-';
    } else if (theByte >= 'a') {
        theByte -= 32;
    }

    if (D_USE_PORTD) {
        set_portd(theByte);
    } else {
        digitalWrite(PIN_D0, theByte & B00000001);
        digitalWrite(PIN_D1, theByte & B00000010);
        digitalWrite(PIN_D2, theByte & B00000100);
        digitalWrite(PIN_D3, theByte & B00001000);
        digitalWrite(PIN_D4, theByte & B00010000);
        digitalWrite(PIN_D5, theByte & B00100000);
        digitalWrite(PIN_D6, theByte & B01000000);
    }
    
    delayMicroseconds(DL2416T_DELAY_US);

    // address 00 = CE1 0, CE2 0
    // address 01 = CE1 1, CE2 0
    // address 02 = CE1 0, CE2 1
    // address 03 = CE1 1, CE2 1

    digitalWrite(PIN_CE1_AL, (display & B00000001) > 0);  // active low so inverted
    digitalWrite(PIN_CE2_AL, (display & B00000010) > 0); // active low so inverted
    
    delayMicroseconds(DL2416T_DELAY_US);

    digitalWrite(PIN_WR_AL, LOW);
    delayMicroseconds(DL2416T_DELAY_US);
    digitalWrite(PIN_WR_AL, HIGH);

    delayMicroseconds(DL2416T_DELAY_US);

    digitalWrite(PIN_CE1_AL, HIGH);
    digitalWrite(PIN_CE2_AL, HIGH);

}
void DL2416T::clear() {
    digitalWrite(PIN_CLR_AL, LOW);
    delayMicroseconds(DL2416T_DELAY_US);
    digitalWrite(PIN_CLR_AL, HIGH);
}


void DL2416T::end() {
    pinMode(PIN_ADDRESS0, INPUT);
    pinMode(PIN_ADDRESS1, INPUT);
    pinMode(PIN_BL_AL, INPUT);
    pinMode(PIN_CE1_AL, INPUT);
    pinMode(PIN_CE2_AL, INPUT);
    pinMode(PIN_CLR_AL, INPUT);
    pinMode(PIN_CU_AL, INPUT);
    pinMode(PIN_CUE, INPUT);
    pinMode(PIN_WR_AL, INPUT);

    if (D_USE_PORTD) {
        DDRD = B00000000;
    } else {
        pinMode(PIN_D0, INPUT);
        pinMode(PIN_D1, INPUT);
        pinMode(PIN_D2, INPUT);
        pinMode(PIN_D3, INPUT);
        pinMode(PIN_D4, INPUT);
        pinMode(PIN_D5, INPUT);
        pinMode(PIN_D6, INPUT);
    }
}

