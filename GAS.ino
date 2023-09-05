int gas = 13;
int led = 7;
int buzzer = 1;
bool estado = 0;
void setup() {
pinMode(gas,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
estado = digitalRead(gas);
if(estado == HIGH){
  digitalWrite(led,LOW);
  }else{
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
    }
}