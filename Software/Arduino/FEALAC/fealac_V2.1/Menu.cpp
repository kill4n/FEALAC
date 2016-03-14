#include "Arduino.h"
#include "Menu.h"
#include <EEPROM.h>

Menu::Menu():
  upDown{ B00100000,
          B01110000,
          B11111000,
          B00000000,
          B11111000,
          B01110000,
          B00100000
        }
{
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnSelect, INPUT);
  eePos = EEPROM.read(0);

  _display->setTextSize(3);
  _display->setCursor(0, 10);
  _display->println("Hg");

  _display->setTextSize(1);
  _display->setTextColor(BLACK);
  _display->setCursor(0, 0);
  _display->println("FEALAC");
}

void Menu::setDisplay(Adafruit_PCD8544 *display)
{
  _display = display;
}
void Menu::showSaved()
{
  _display->setTextColor(BLACK);
  _display->setCursor(41, 10);
  if (eePos < 10)
    _display->print("00");
  if ((eePos < 100) && (eePos >= 10))
    _display->print("0");
  _display->print(eePos);
  _display->setCursor(59, 10);
  _display->print("/100");
}

void Menu::showOptions(int value)
{
  _display->setCursor(32, 40);
  if (pos == value)
  {
    _display->setTextColor(WHITE);
    _display->fillRect(31, 39, 47, 9, BLACK);
  }
  else
  {
    _display->setTextColor(BLACK);
  }
  String opt="";
  switch (value)
  {
    case 0:

    break;
    default:

    break;
  }

  _display->println(opt);
}

void Menu::display(int val)
{
  int i = 0;
  pos = val;

  _display->setCursor(1, 40);
  _display->println("CH05");

  _display->setTextColor(BLACK);
  _display->setCursor(41, 25);
  _display->print("----");
  _display->println("ppb");

  _display->drawBitmap(25, 40,  upDown, 5, 7, 1);
  _display->drawBitmap(79, 40,  upDown, 5, 7, 1);
}

void Menu::checkButton()
{
  if (digitalRead(btnUp) == HIGH) {
    while (digitalRead(btnUp) == HIGH);
    if (pos < 2)
      pos++;
    else
      pos = 0;

  }
}

