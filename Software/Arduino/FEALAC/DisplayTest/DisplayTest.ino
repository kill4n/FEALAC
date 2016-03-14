#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
byte BAT_FIN_E[8] = { B11110,
                      B00010,
                      B00001,
                      B00001,
                      B00001,
                      B00010,
                      B11110,};
byte BAT_FIN_M[8] = { B11110,
                      B11110,
                      B11101,
                      B11001,
                      B00001,
                      B00010,
                      B11110,};
byte BAT_FIN_F[8] = { B11110,
                      B11110,
                      B11111,
                      B11111,
                      B11111,
                      B11110,
                      B11110,};
byte BAT_MID_E[8] = { B11111,
                      B10000,
                      B10000,
                      B10000,
                      B10000,
                      B10000,
                      B11111,};
byte BAT_MID_M[8] = { B11111,
                      B11111,
                      B11100,
                      B11100,
                      B11000,
                      B10000,
                      B11111,};
byte BAT_MID_F[8] = { B11111,
                      B11111,
                      B11111,
                      B11111,
                      B11111,
                      B11111,
                      B11111,};


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.createChar(0, BAT_MID_E);
  lcd.createChar(1, BAT_FIN_E);
  lcd.createChar(2, BAT_MID_M);
  lcd.createChar(3, BAT_FIN_M);
  lcd.createChar(4, BAT_MID_F);
  lcd.createChar(5, BAT_FIN_F);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Concentration Hg");
  
  //lcd.print("1202 ppb ");
  //lcd.setCursor(12, 1);
  
  lcd.write(byte(0));  
  lcd.write(byte(1));
  lcd.print(" ");
  lcd.write(byte(2));  
  lcd.write(byte(1));
  lcd.print(" ");
  lcd.write(byte(4));  
  lcd.write(byte(1));
  lcd.print(" ");
  lcd.write(byte(4));  
  lcd.write(byte(3));
  lcd.print(" ");
  lcd.write(byte(4));  
  lcd.write(byte(5));
  lcd.print(" ");
  /*
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));

  lcd.setCursor(0, 1);

  */
}

void loop() {
  lcd.display();
  delay(500);
}

