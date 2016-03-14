#include "Arduino.h"
#include "Menu.h"
#include <EEPROM.h>

#define OPT_LENGTH 5
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
  for (int i = 0; i < 5; i++)
    pinMode(CH[i], INPUT);
  pinMode(ledMeasure, OUTPUT);

  eePos = EEPROM.read(0);
}

void Menu::setDisplay(Adafruit_PCD8544 *display)
{
  _display = display;

  _display->setTextSize(3);
  _display->setTextColor(BLACK);
  _display->setCursor(0, 12);
  _display->println("Hg");
  _display->setTextSize(1);
  _display->setCursor(0, 0);
  _display->println("FEALAC");
  showChannel();
}
void Menu::showSaved()
{
  _display->setTextColor(BLACK);
  _display->fillRect(41, 15, 45, 9, WHITE);
  _display->setCursor(41, 15);
  if (eePos < 10)
    _display->print("00");
  if ((eePos < 100) && (eePos >= 10))
    _display->print("0");
  _display->print(eePos);
  _display->setCursor(59, 15);
  _display->print("/100");
}
void Menu::showChannel()
{
  _display->setTextColor(WHITE);
  _display->fillRect(41, 0, 25, 9, BLACK);
  _display->setCursor(42, 1);
  _display->print("CH0");
  _display->print(channel + 1);
}
void Menu::showMeasured()
{
  _display->setTextColor(BLACK);
  _display->fillRect(41, 30, 45, 9, WHITE);
  _display->setCursor(41, 30);
  if (measure < 0)
    _display->print("----");
  if ((measure < 10) && (measure >= 0))
    _display->print("000");
  if ((measure < 100) && (measure >= 10))
    _display->print("00");
  if ((measure < 1000) && (measure >= 100))
    _display->print("0");

  if (measure >= 0)
    _display->print(measure);

  _display->println("ppb");
}
void Menu::showOptions(int value)
{
  _display->setCursor(2, 40);
  if (pos == value)
  {
    _display->setTextColor(WHITE);
    _display->fillRect(1, 39, 76, 9, BLACK);
  }
  else
  {
    _display->setTextColor(BLACK);
    _display->fillRect(1, 39, 76, 9, WHITE);
  }
  String opt = "";
  switch ((OPTIONS)pos)
  {
    case OPT_MEASURE: opt = "Measure"; break;
    case OPT_SAVE: opt = "Save"; break;
    case OPT_DELETE: opt = "Delete"; break;
    case OPT_RESET: opt = "Reset"; break;
    case OPT_SYNC: opt = "Sync"; break;
    case OPT_CHANNEL: opt = "Channel 0";
      opt.concat(channel + 1); break;
    default: opt = "None"; break;
  }
  _display->println(opt);
}

bool Menu::sure()
{
  bool answer = false;
  bool salir = true;
  while (salir)
  {
    delay(10);
    _display->setTextColor(BLACK);
    _display->fillRect(0, 39, 84, 9, WHITE);
    _display->setCursor(1, 40);
    _display->print("Sure: ");
    if (!answer) {
      _display->setTextColor(BLACK);
      _display->fillRect(39, 39, 19, 9, WHITE);
    }
    else {
      _display->setTextColor(WHITE);
      _display->fillRect(39, 39, 19, 9, BLACK);
    }
    _display->setCursor(40, 40);
    _display->print("YES");


    if (answer) {
      _display->setTextColor(BLACK);
      _display->fillRect(64, 39, 13, 9,  WHITE);
    }
    else {
      _display->setTextColor(WHITE);
      _display->fillRect(64, 39, 13, 9, BLACK);
    }
    _display->setCursor(65, 40);
    _display->print("NO");

    if (digitalRead(btnUp) == HIGH) {
      while (digitalRead(btnUp) == HIGH);
      answer = !answer;
    }
    if (digitalRead(btnDown) == HIGH) {
      while (digitalRead(btnDown) == HIGH);
      answer = !answer;
    }

    if (digitalRead(btnSelect) == HIGH) {
      while (digitalRead(btnSelect) == HIGH);
      salir = false;
    }
    _display->display();
  }

  return answer;
}

void Menu::display(int val)
{
  int i = 0;
  showSaved();

  _display->setCursor(1, 40);
  //_display->println("CH05");

  showMeasured();
  showOptions(val);
  //_display->drawBitmap(25, 40,  upDown, 5, 7, 1);
  _display->drawBitmap(79, 40,  upDown, 5, 7, 1);
}

void Menu::checkButton()
{
  if (digitalRead(btnUp) == HIGH) {
    while (digitalRead(btnUp) == HIGH);
    if (pos < OPT_LENGTH)
      pos++;
    else
      pos = 0;
  }
  if (digitalRead(btnDown) == HIGH) {
    while (digitalRead(btnDown) == HIGH);
    if (pos > 0)
      pos--;
    else
      pos = OPT_LENGTH;
  }

  if (digitalRead(btnSelect) == HIGH) {
    while (digitalRead(btnSelect) == HIGH);
    switch ((OPTIONS)pos)
    {
      case OPT_MEASURE: //"Measure";
        digitalWrite(ledMeasure, HIGH);
        measure = analogRead(CH[channel]);
        //measure = map(measure,0,1023,0,9999);
        delay(1000);
        digitalWrite(ledMeasure, LOW);
        showMeasured();
        pos = OPT_SAVE;
        break;
      case OPT_SYNC: //"Sync";
        //sync code
        measure = -1;
        pos = OPT_MEASURE;
        break;
      case OPT_SAVE: //"Save"
        if (measure >= 0)
        {
          if (eePos < 100)
            eePos++;
          EEPROM.write(eePos + 1, measure);
          EEPROM.write(0, eePos);
          measure = -1;
        }
        showSaved();
        pos = OPT_MEASURE;
        break;
      case OPT_DELETE: //"Delete"
        if (sure())
        {
          if (eePos > 0)
            eePos--;
          EEPROM.write(0, eePos);
          showSaved();
          measure = -1;
        }
        pos = OPT_MEASURE;
        break;
      case OPT_RESET: //"Reset"
        if (sure())
        {
          eePos = 0;
          EEPROM.write(0, eePos);
          showSaved();
          measure = -1;
        }
        pos = OPT_MEASURE;
        break;
      case OPT_CHANNEL:
        channel++;
        if (channel >= 5)
          channel = 0;
        showChannel();
        measure = -1;
        break;
      default: //"None"
        break;
    }
  }
}
//measure
