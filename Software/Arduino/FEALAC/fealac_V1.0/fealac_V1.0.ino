//delacrar librerias
#include "BatteryVisualizer.h"
#include "MenuLCD.h"
#include <LiquidCrystal.h>
//crear objetos
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
BatteryVisualizer battV;
MenuLCD menu;
//Texto inicial
String intro[2] = { "FEALAC device", "Hg Concentration" };

void setup() {
  //paso que lcd estoy usando a los objetos bateria y menu
  battV.setLCD(&lcd);
  menu.setLCD(&lcd);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);  
  //ubica el cursor
  lcd.setCursor(0, 0);
  //imprime un mensaje
  lcd.print(intro[0]);
  lcd.setCursor(0, 1);
  lcd.print(intro[1]);
  //muestra texto en pantalla
  lcd.display();
  //espera de 5 seg
  delay(5000);
  //inicia menu
  menu.showMenu();
}
int val = 0;
void loop() {
  //demora 
  delay(100);
  val = analogRead(A1);
  switch (menu.checkButton())
  {
    case 1:
    case 2:
    case 3:
      menu.showMenu();
      break;
    default:
      break;
  }
  //muestra bateria
  int d= map(val, 0, 
  battV.display(1);
}

