#include "Arduino.h"
#include "MenuLCD.h"

#include <EEPROM.h>

void MenuLCD::lcdClear() {
  _lcd->setCursor(0, 0);
  _lcd->print("                ");
  _lcd->setCursor(0, 1);
  _lcd->print("                ");
}

MenuLCD::MenuLCD()
{
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnSelect, INPUT);
  eePos =EEPROM.read(0);
}

void MenuLCD::setLCD(LiquidCrystal *lcd)
{
  _lcd = lcd;
}

int MenuLCD::checkButton()
{
  if (digitalRead(btnUp) == HIGH) {
    while (digitalRead(btnUp) == HIGH);
    if (pos < 2)
      pos++;
    else
      pos = 0;
    return 1;
  }
  else {
    if (digitalRead(btnDown) == HIGH) {
      while (digitalRead(btnDown) == HIGH);
      if (pos > 0)
        pos--;
      else
        pos = 2;
      return 2;
    }
    else {
      if (digitalRead(btnSelect) == HIGH) {
        while (digitalRead(btnSelect) == HIGH);
        switch (nivel)
        {
          case 0:
            switch (pos)
            {
              case 0:
                //sincronizar
                lcdClear();
                _lcd->setCursor(0, 0);
                _lcd->print("sincronizar");
                
                delay(2000);
                break;
              case 1:
                //medir
                nivel++;
                pos = 0;
                lcdClear();
                _lcd->setCursor(0, 0);
                _value = analogRead(A0);
                _lcd->print("Hg Value: ");
                _value = map(_value, 0, 1023, 0, 255);
                _lcd->print(_value);
                delay(4000);
                break;
              case 2:
                //salir
                _lcd->clear();
                _lcd->begin(16, 2);
                _lcd->setCursor(0, 0);
                _lcd->print(intro[0]);
                _lcd->setCursor(0, 1);
                _lcd->print(intro[1]);
                delay(5000);
                break;
              default:
                break;
            }
            break;
          case 1:
            switch (pos)
            {
              case 0:
                //save
                lcdClear();
                _lcd->setCursor(0, 0);
                _lcd->print("Value saved");                
                EEPROM.write(eePos, _value);
                eePos++;
                EEPROM.write(0, eePos);
                if (eePos > 255)
                  eePos == 1;
                delay(2000);
                break;
              case 1:
                //delete
                lcdClear();
                _lcd->setCursor(0, 0);
                _lcd->print("Value deleted");
                delay(2000);
                break;
              case 2:
                //back
                lcdClear();
                _lcd->setCursor(0, 0);
                _lcd->print("Going back");
                delay(2000);
                nivel--;
                pos = 0;
                break;
              default:
                break;
            }
            break;
          default:
            break;
        }
        return 3;
      }
      else {
        return 0;
      }
    }
  }
  return 0;
}

void MenuLCD::showMenu()
{
  lcdClear();
  _lcd->setCursor(0, 0);
  _lcd->print(">");
  switch (nivel) {
    case 0:
      switch (pos) {
        case 0:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel0[0]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel0[1]);
          break;
        case 1:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel0[1]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel0[2]);
          break;
        case 2:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel0[2]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel0[0]);
          break;
        default:
          break;
      }
      break;
    case 1:
      switch (pos) {
        case 0:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel1[0]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel1[1]);
          break;
        case 1:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel1[1]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel1[2]);
          break;
        case 2:
          _lcd->setCursor(1, 0);
          _lcd->print(nivel1[2]);
          _lcd->setCursor(1, 1);
          _lcd->print(nivel1[0]);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}


