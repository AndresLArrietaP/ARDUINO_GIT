#include <LiquidCrystal.h>
#include <DHT.h>  // Agrega la librería para el sensor DHT11


#define DHTPIN 10  // Define el pin al que está conectado el sensor DHT11
#define DHTTYPE DHT11  // Especifica el tipo de sensor (DHT11 en este caso)
DHT dht(DHTPIN, DHTTYPE);  // Crea una instancia del sensor DHT11

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int numero = 0;


LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();  // Inicializa el sensor DHT11
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");

  lcd.setCursor(0, 1);
  lcd.print("Humedad: ");

  delay(1000);  // Pausa para estabilidad en la lectura del sensor

  float temperatura = dht.readTemperature();  // Lee la temperatura en grados Celsius
  float humedad = dht.readHumidity();  // Lee la humedad en porcentaje

  lcd.setCursor(13, 0);
  lcd.print(temperatura);
  lcd.print(" C");

  lcd.setCursor(10, 1);
  lcd.print(humedad);
  lcd.print(" %");

  delay(3000);  // Pausa antes de actualizar los valores en el LCD
  lcd.clear();
}
