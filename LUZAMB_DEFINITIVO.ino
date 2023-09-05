int LED = 9;
int RESISTENCIA = A0;
int entrada = 0;

void setup(){
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop(){
  entrada = analogRead(RESISTENCIA); //0 - 1023
  Serial.println(entrada);

  entrada = (entrada * 255) / 1023;

  analogWrite(LED, entrada);

  delay(500);
  
}