#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int prs = 12;
int pe = 11;
int pd4 = 5;
int pd5 = 4;
int pd6 = 3;
int pd7 = 2;

LiquidCrystal lcd(prs, pe, pd4, pd5, pd6, pd7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: "); 
  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");
  delay(1000);
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  lcd.setCursor(13, 0);
  lcd.print(temperatura);
  lcd.print(" C");
  lcd.setCursor(10, 1);
  lcd.print(humedad);
  lcd.print(" %");
  delay(3000);

  lcd.clear();
}

