
#include "Arduino.h"
#include <stdint.h>
#include "Print.h"

class DLX3416 {
  private:
    uint8_t PIN_ADDRESS0;
    uint8_t PIN_ADDRESS1;
    uint8_t PIN_BL_AL;
    uint8_t PIN_CE1;
    uint8_t PIN_CE2;
    uint8_t PIN_CE3_AL;
    uint8_t PIN_CE4_AL;
    uint8_t PIN_CLR_AL;
    uint8_t PIN_CU;
    uint8_t PIN_CUE;
    uint8_t PIN_D0;
    uint8_t PIN_D1;
    uint8_t PIN_D2;
    uint8_t PIN_D3;
    uint8_t PIN_D4;
    uint8_t PIN_D5;
    uint8_t PIN_D6;
    uint8_t PIN_WR_AL;
    uint8_t D_USE_PORTD;

  public:
    DLX3416(uint8_t pinA0 = 8, uint8_t pinA1 = 9, uint8_t pinBL_AL = 12, uint8_t pinCE1 = 12, uint8_t pinCE2 = 12, uint8_t pinCE3_AL = 12, uint8_t pinCE4_AL = 12, uint8_t pinCLR_AL = A2, uint8_t pinCU = A0, uint8_t pinCUE = A3, uint8_t pinD0 = 0, uint8_t pinD1 = 1, uint8_t pinD2 = 2, uint8_t pinD3 = 3, uint8_t pinD4 = 4, uint8_t pinD5 = 5, uint8_t pinD6 = 6, uint8_t pinWR_AL = 7, uint8_t usePortD = true);
    
    void begin() ;
    void set_portd(uint8_t theByte);

    void writeByte(uint8_t display, uint8_t address, uint8_t theByte) ;
    void clear() ;
};