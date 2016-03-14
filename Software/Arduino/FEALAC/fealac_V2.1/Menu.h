#ifndef MENU_H
#define MENU_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

class Menu
{
  public:
    Menu();
    void setDisplay(Adafruit_PCD8544 *display);
    void display(int val);
    void checkButton();
  private:
    void showSaved();
    void showOptions(int value);
    Adafruit_PCD8544 *_display;
    int pos = 0;
    unsigned char upDown[7];
    const int btnUp = 7;
    const int btnDown = 6;
    const int btnSelect = 5;
    int eePos = 1;
};
#endif //Menu_h
