#include <DHT.h>  // Agrega la librería para el sensor DHT11

#define DHTPIN 10  // Define el pin al que está conectado el sensor DHT11
#define DHTTYPE DHT11  // Especifica el tipo de sensor (DHT11 en este caso)
DHT dht(DHTPIN, DHTTYPE);  // Crea una instancia del sensor DHT11

int sensorPin = A1; // Pin analógico donde está conectado el sensor de humedad de suelo
int ldrPin = A2;    // Pin analógico donde está conectado el sensor de luz ambiental
int umbral = 750;   // Umbral para encender el LED

int mq2Pin = A0;     // Pin analógico para el sensor de gas MQ-2
int ledPinGas = 7;   // Pin para el LED rojo del sensor de gas
int buzzerPinGas = 6; // Pin para el zumbador del sensor de gas
int umbralGas = 180; // Umbral para la detección de gas (ajusta según sea necesario)
int flameDetected = 0; // Variable para rastrear la detección de fuego

int bomba = 9;   // Pin de control de la bomba de agua
int humedad = 0; // Variable para la lectura de la humedad del suelo

void setup() {
  // Inicializamos el sensor DHT11
  dht.begin();

  // Inicializamos el Monitor Serie
  Serial.begin(9600);

  // Inicializamos el pin del LED
  pinMode(13, OUTPUT);

  // Inicializamos los pines del sensor de gas MQ-2
  pinMode(mq2Pin, INPUT);
  pinMode(ledPinGas, OUTPUT);
  pinMode(buzzerPinGas, OUTPUT);

  // Inicializamos el pin de control de la bomba de agua
  pinMode(bomba, OUTPUT);
}

void loop() {
  // Leemos la temperatura y la humedad del sensor DHT11
  float temperatura = dht.readTemperature();
  float humedadDHT = dht.readHumidity();
  // Leemos la lectura del sensor de humedad de suelo
  int lectura = analogRead(sensorPin);
  // Leemos la lectura del sensor de luz ambiental
  int LDRestado = analogRead(ldrPin);
  // Mostramos los valores en el Monitor Serie
  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1); // Mostramos la temperatura con un decimal
  Serial.println(" C");
  Serial.print("Humedad: ");
  Serial.print(humedadDHT, 1); // Mostramos la humedad con un decimal
  Serial.println(" %");
  // Mostramos el resultado de las condiciones en el Monitor Serie
  
  if (lectura >= 1000) {
    Serial.println("FUERA DEL SUELO");
  } else if (lectura < 1000 && lectura >= 600) {
    Serial.println("SUELO ESTA SECO ");
  } else if (lectura < 600 && lectura >= 370) {
    Serial.println("SUELO HUMEDO");
  } else if (lectura < 370) {
    Serial.println("SENSOR EN AGUA ");
  }

  // Enviamos la lectura del sensor de la humedad del suelo al Monitor Serie
  Serial.print("Humedad del suelo: ");
  Serial.println(lectura);

  // Enviamos la lectura del sensor 
  //de luz ambiental al Monitor Serie
  Serial.print("Luz ambiental: ");
  Serial.println(LDRestado);

  // Verificar si el valor del LDR supera el umbral
  if (umbral > LDRestado) {
    digitalWrite(13, LOW);  // Encender el LED
  } else {
    digitalWrite(13, HIGH); // Apagar el LED
  }

  // Leemos el valor del sensor de gas MQ-2
  int sensorValue = analogRead(mq2Pin);
  Serial.print("Valor del sensor de gas: ");
  Serial.println(sensorValue);
  // Comprueba si el valor del sensor MQ-2 supera el umbral para la detección de gas
  if (sensorValue > umbralGas) {
    flameDetected = 1;  // Se detecta el gas
    digitalWrite(ledPinGas, HIGH);
    digitalWrite(buzzerPinGas, HIGH);
  } else {
    flameDetected = 0;  // No se detecta el gas
    digitalWrite(ledPinGas, LOW);
    digitalWrite(buzzerPinGas, LOW);
  }

  // Leemos la humedad del suelo 
  humedad = analogRead(A1);
  // Comprueba si la humedad del suelo está dentro del rango deseado para activar la bomba
  if (humedad >= 721 && humedad <= 1024) {
    digitalWrite(bomba, LOW); // Apagar la bomba
  } else {
    digitalWrite(bomba, HIGH); // Encender la bomba
  }
  Serial.println("--------------------------");
  delay(2000); // Esperamos unos segundos antes de volver a leer los valores
}