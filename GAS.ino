int pgas = 13;
int pled = 7;
int pbuzzer = 1;
bool est = 0;

void setup() {
  pinMode(pgas, INPUT);
  pinMode(pled, OUTPUT);
  pinMode(pbuzzer, OUTPUT);
}

void loop() {
  est = digitalRead(pgas);
  if (est == HIGH) {
    digitalWrite(pled, LOW);
  } else {
    digitalWrite(pled, HIGH);
    digitalWrite(pbuzzer, HIGH);
    delay(500);
    digitalWrite(pbuzzer, LOW);
    delay(500);
  }
}
