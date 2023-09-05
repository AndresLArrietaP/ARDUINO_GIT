#include <LiquidCrystal.h>

int prs = 12;
int pe = 11;
int pd4 = 5;
int pd5 = 4;
int pd6 = 3;
int pd7 = 2;

LiquidCrystal lcd(prs,pe, pd4, pd5, pd6, pd7);

void setup() {

}

void loop(){
  int hum = analogRead(A1);
  int hump = map(hum,1023,0,0,100); //A PORCENTAJE


  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.setCursor(10, 0);
  lcd.print(hump);
  lcd.print(" %");
  lcd.setCursor(0, 1);
    // lecturas entre 1000 - 1023
  if (hum >= 1000) {
    lcd.print("SIN HUMEDAD");
  }else if (hum <1000 && hum >= 600) {
    lcd.print("SUELO SECO");
  }else if (hum < 600 && hum >= 370) {
    lcd.print("SUELO HUMEDO");
  }else if (hum < 370) {
    lcd.print("EN AGUA");
  }
  delay(1000);
  lcd.clear();

}
