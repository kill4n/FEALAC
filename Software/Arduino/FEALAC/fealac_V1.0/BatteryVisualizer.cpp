#include "Arduino.h"
#include "BatteryVisualizer.h"

BatteryVisualizer::BatteryVisualizer()
{
  _cant = 2;
}
void BatteryVisualizer::setLCD(LiquidCrystal * lcd)
{
  _lcd = lcd;
  _lcd->createChar(0, BAT_MID_E);
  _lcd->createChar(1, BAT_FIN_E);
  _lcd->createChar(2, BAT_MID_M);
  _lcd->createChar(3, BAT_FIN_M);
  _lcd->createChar(4, BAT_MID_F);
  _lcd->createChar(5, BAT_FIN_F);
}
void BatteryVisualizer::display(int value)
{
  int val = value;
  _lcd->setCursor(16 - _cant, 2);
  switch (val)
  {
    case 0:
      _lcd->write(byte(0));
      _lcd->write(byte(1));
      break;
    case 1:
      _lcd->write(byte(2));
      _lcd->write(byte(1));
      break;
    case 2:
      _lcd->write(byte(4));
      _lcd->write(byte(1));
      break;
    case 3:
      _lcd->write(byte(4));
      _lcd->write(byte(3));
      break;
    case 4:
      _lcd->write(byte(4));
      _lcd->write(byte(5));
    default:
      break;
  }
}
