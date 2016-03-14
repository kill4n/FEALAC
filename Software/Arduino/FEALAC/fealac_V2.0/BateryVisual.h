#ifndef BateryVisual_h
#define BateryVisual_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class BateryVisual
{
  public:
    BateryVisual();
    void setDisplay(Adafruit_PCD8544 *display);
    void display();
  private:
    const int ADC1 = 14;
    int valBat = 0;
    Adafruit_PCD8544 *_display;
    unsigned char BAT_VAL_0[10];
    unsigned char BAT_VAL_1[10];
    unsigned char BAT_VAL_2[10];
    unsigned char BAT_VAL_3[10];
    unsigned char BAT_VAL_4[10];
    unsigned char BAT_VAL_5[10];
};
#endif
