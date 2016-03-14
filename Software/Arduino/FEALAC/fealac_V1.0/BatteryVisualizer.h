#ifndef BatteryVisualizer_h
#define BatteryVisualizer_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class BatteryVisualizer
{
  public:
    BatteryVisualizer();
    void setLCD(LiquidCrystal * lcd);
    void display(int value);
  private:
    byte BAT_FIN_E[8] = { B11110,
                          B00010,
                          B00001,
                          B00001,
                          B00001,
                          B00010,
                          B11110,
                        };
    byte BAT_FIN_M[8] = { B11110,
                          B11110,
                          B11101,
                          B11001,
                          B00001,
                          B00010,
                          B11110,
                        };
    byte BAT_FIN_F[8] = { B11110,
                          B11110,
                          B11111,
                          B11111,
                          B11111,
                          B11110,
                          B11110,
                        };
    byte BAT_MID_E[8] = { B11111,
                          B10000,
                          B10000,
                          B10000,
                          B10000,
                          B10000,
                          B11111,
                        };
    byte BAT_MID_M[8] = { B11111,
                          B11111,
                          B11100,
                          B11100,
                          B11000,
                          B10000,
                          B11111,
                        };
    byte BAT_MID_F[8] = { B11111,
                          B11111,
                          B11111,
                          B11111,
                          B11111,
                          B11111,
                          B11111,
                        };
    int _cant;
    LiquidCrystal *_lcd;

};

#endif //BatteryVisualizer_h
