int pled = 9;
int pres = A0;
int ent = 0;

void setup(){
  pinMode(pled, OUTPUT);
  digitalWrite(pled, LOW);
  Serial.begin(9600);
}

void loop(){
  ent= analogRead(pres);
  Serial.println(ent);
  ent = (ent * 255) / 1023;
  analogWrite(pled, ent);
  delay(500);
}
