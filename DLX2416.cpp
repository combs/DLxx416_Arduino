


class DLX2416 {
  private:
    uint8_t PIN_A0 = 8;
    uint8_t PIN_A1 = 9;
    uint8_t PIN_BL_AL = 12;
    uint8_t PIN_CE1_AL = 12; // null val in my application
    uint8_t PIN_CE2_AL = 12;
    uint8_t PIN_CLR_AL = A2;
    uint8_t PIN_CU_AL = A0;
    uint8_t PIN_CUE = A3;
    uint8_t PIN_D0 = 0;
    uint8_t PIN_D1 = 1;
    uint8_t PIN_D2 = 2;
    uint8_t PIN_D3 = 3;
    uint8_t PIN_D4 = 4;
    uint8_t PIN_D5 = 5;
    uint8_t PIN_D6 = 6;
    uint8_t PIN_WR_AL = 7;
    uint8_t D_USE_PORTD = true;

  public:
    DLX2416(uint8_t pinA0 = 8, uint8_t pinA1 = 9, uint8_t pinBL_AL = 12, uint8_t pinCE1_AL = 12, uint8_t pinCE2_AL = 12, uint8_t pinCLR_AL = A2, uint8_t pinCU_AL = A0, uint8_t pinCUE = A3, uint8_t pinD0 = 0, uint8_t pinD1 = 1, uint8_t pinD2 = 2, uint8_t pinD3 = 3, uint8_t pinD4 = 4, uint8_t pinD5 = 5, uint8_t pinD6 = 6, uint8_t pinWR_AL = 7, uint8_t usePortD = true) {

        PIN_A0 = pinA0;
        PIN_A1 = pinA1;
        PIN_BL_AL = pinBL_AL;
        PIN_CE1_AL = pinCE1_AL; // null val in my application
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
    void begin() {
        pinMode(PIN_A0, OUTPUT);
        pinMode(PIN_A1, OUTPUT);
        pinMode(PIN_BL_AL, OUTPUT);
        pinMode(PIN_CE1_AL, OUTPUT);
        pinMode(PIN_CE2_AL, OUTPUT);
        pinMode(PIN_CLR_AL, OUTPUT);
        pinMode(PIN_CU_AL, OUTPUT);
        pinMode(PIN_CUE, OUTPUT);
        pinMode(PIN_D0, OUTPUT);
        pinMode(PIN_D1, OUTPUT);
        pinMode(PIN_D2, OUTPUT);
        pinMode(PIN_D3, OUTPUT);
        pinMode(PIN_D4, OUTPUT);
        pinMode(PIN_D5, OUTPUT);
        pinMode(PIN_D6, OUTPUT);
        pinMode(PIN_WR_AL, OUTPUT);
        if (D_USE_PORTD) {
            DDRD = B11111111;
            set_portd(B00000000);
        }
        digitalWrite(PIN_BL_AL, HIGH);
        digitalWrite(PIN_CE1_AL, HIGH);
        digitalWrite(PIN_CE2_AL, HIGH);
        digitalWrite(PIN_CLR_AL, HIGH);
        digitalWrite(PIN_CU_AL, HIGH);
        digitalWrite(PIN_WR_AL, HIGH);
               
    }
    void set_portd(uint8_t theByte) {
        uint8_t bit7 = PORTD && B10000000; // save current bit 7
        theByte = theByte && B01111111; // wipe bit 7 in new val
        PORTD = theByte || bit7; // write new val
    }

    void writeByte(uint8_t display, uint8_t address, uint8_t theByte) {
        digitalWrite(PIN_A0, address && b00000001);
        digitalWrite(PIN_A1, address && b00000010);
        
        if (D_USE_PORTD) {
            set_portd(theByte);
        } else {
            digitalWrite(PIN_D0, theByte && B00000001);
            digitalWrite(PIN_D1, theByte && B00000010);
            digitalWrite(PIN_D2, theByte && B00000100);
            digitalWrite(PIN_D3, theByte && B00001000);
            digitalWrite(PIN_D4, theByte && B00010000);
            digitalWrite(PIN_D5, theByte && B00100000);
            digitalWrite(PIN_D6, theByte && B01000000);
            
        }
        
        digitalWrite(PIN_CE1_AL, (display && b00000001) == 0);  // active low so inverted
        digitalWrite(PIN_CE2_AL, (display && b00000010) == 0); // active low so inverted
        
        delayMicroseconds(1);

        digitalWrite(PIN_CE1_AL, HIGH);
        digitalWrite(PIN_CE2_AL, HIGH);

    }
    void clear() {
        digitalWrite(PIN_CLR_AL, LOW);
        delayMicroseconds(1);
        digitalWrite(PIN_CLR_AL, HIGH);
        
    }
}




