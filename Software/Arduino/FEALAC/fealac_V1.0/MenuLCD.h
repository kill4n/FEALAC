#ifndef MenuLCD_h
#define MenuLCD_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class MenuLCD
{
  public:
    MenuLCD();
    void setLCD(LiquidCrystal *lcd);
    int checkButton();
    void showMenu();
  private:
    void lcdClear();
    int _value;
    LiquidCrystal *_lcd;
    const int btnUp = 11;
    const int btnDown = 12;
    const int btnSelect = 13;
    int eePos = 1;
    int pos = 0;
    int nivel = 0;
    String nivel0[3] = { "Sync", "Measure", "Exit" };
    String nivel1[3] = { "Save", "Delete", "Back" };
    String intro[2] = { "FEALAC device", "Hg Concentration" };

};

#endif //MenuLCD_h
