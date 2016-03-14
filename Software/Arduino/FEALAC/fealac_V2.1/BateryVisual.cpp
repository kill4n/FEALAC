#include "Arduino.h"
#include "BateryVisual.h"

BateryVisual::BateryVisual():
  BAT_VAL_0{  B11111111, B11110000,
              B10000000, B00011000,
              B10000000, B00011000,
              B10000000, B00011000,
              B11111111, B11110000
           },
  BAT_VAL_1{  B11111111, B11110000,
              B11100000, B00011000,
              B11100000, B00011000,
              B11100000, B00011000,
              B11111111, B11110000
           },
  BAT_VAL_2{  B11111111, B11110000,
              B11111000, B00011000,
              B11111000, B00011000,
              B11111000, B00011000,
              B11111111, B11110000
           },
  BAT_VAL_3{  B11111111, B11110000,
              B11111110, B00011000,
              B11111110, B00011000,
              B11111110, B00011000,
              B11111111, B11110000
           },
  BAT_VAL_4{  B11111111, B11110000,
              B11111111, B10011000,
              B11111111, B10011000,
              B11111111, B10011000,
              B11111111, B11110000
           },
  BAT_VAL_5{  B11111111, B11110000,
              B11111111, B11111000,
              B11111111, B11111000,
              B11111111, B11111000,
              B11111111, B11110000
           }
{

}

void BateryVisual::setDisplay(Adafruit_PCD8544 *display)
{
  _display = display;
}

void BateryVisual::display(int val)
{
  _display->fillRect(70, 0, 83, 6, WHITE);
  switch (val)
  {
    case 0:
      _display->drawBitmap(70, 0,  BAT_VAL_0, 16, 5, 1);
      break;
    case 1:
      _display->drawBitmap(70, 0,  BAT_VAL_1, 16, 5, 1);
      break;
    case 2:
      _display->drawBitmap(70, 0,  BAT_VAL_2, 16, 5, 1);
      break;
    case 3:
      _display->drawBitmap(70, 0,  BAT_VAL_3, 16, 5, 1);
      break;
    case 4:
      _display->drawBitmap(70, 0,  BAT_VAL_4, 16, 5, 1);
      break;
    case 5:
      _display->drawBitmap(70, 0,  BAT_VAL_5, 16, 5, 1);
      break;
    default:
      _display->drawBitmap(70, 0,  BAT_VAL_0, 16, 5, 1);
      break;
  }
  //_display->display();
}

