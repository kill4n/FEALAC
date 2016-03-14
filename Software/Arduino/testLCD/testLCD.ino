#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00011100, B00111000,
  B00111110, B01111100,
  B01111111, B11111110,
  B11111111, B11111111,
  B11111111, B11111111,
  B11111111, B11111111,
  B11111111, B11111111,
  B11111111, B11111111,
  B01111111, B11111110,
  B00111111, B11111100,
  B00011111, B11111000,
  B00001111, B11110000,
  B00000111, B11100000,
  B00000011, B11000000,
  B00000001, B10000000,
  B00000000, B00000000 };

void setup()   {
  Serial.begin(9600);

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);
  display.begin();
  // miniature bitmap display
  display.clearDisplay();
  display.drawBitmap(0, 0,  logo16_glcd_bmp, 16, 16, 1);
  display.display();
  delay(2000);
  //display.clearDisplay();

  // text display tests
  display.setCursor(0,17);
  display.setTextSize(1);
  display.setTextColor(BLACK);  
  display.println("Te amo gatis");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println("mucho mucho");
  display.setTextColor(BLACK);
  display.println("con todo mi ser");
  display.display();
  delay(2000);
}

void loop() {
  
}
