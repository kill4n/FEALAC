#ifndef MENU_H
#define MENU_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
enum OPTIONS {
  OPT_MEASURE = 0,
  OPT_SYNC = 1,
  OPT_SAVE = 2,
  OPT_DELETE = 3,
  OPT_RESET = 4,
  OPT_CHANNEL = 5

};

class Menu
{
  public:
    Menu();
    void setDisplay(Adafruit_PCD8544 *display);
    void display(int val);
    void checkButton();
  private:
    void showSaved();
    void showMeasured();
    void showOptions(int value);
    void showChannel();
    bool sure();
    
    Adafruit_PCD8544 *_display;
    int pos = 0;
    unsigned char upDown[7];
    int channel = 0;
    const int CH[5] = {15, 16, 17, 18, 19};
    const int btnUp = 7;
    const int btnDown = 6;
    const int btnSelect = 5;
    const int ledMeasure = 4;
    int eePos = 1;
    int measure = -1;
};
#endif //Menu_h
