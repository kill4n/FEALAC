//delacrar librerias
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "BateryVisual.h"
#include "Menu.h"
//crear objetos
Adafruit_PCD8544 pantalla = Adafruit_PCD8544(8, 9, 10, 11, 12);
BateryVisual battV;
Menu menu;

void setup() {
  //paso que lcd estoy usando a los objetos bateria y menu
  battV.setDisplay(&pantalla);
  menu.setDisplay(&pantalla);
  // you can change the contrast around to adapt the display
  // for the best viewing!
  pantalla.begin();
  pantalla.setContrast(50);
  pantalla.clearDisplay();
  
  menu.display(0);
  pantalla.display();
}
int val = 0;
void loop() {
  //demora
  //delay(100);
  //val = analogRead(A1);
  //menu.display(val);
  battV.display(val++);
  delay(500);
  if (val > 5)
    val = 0;
  pantalla.display();
}

