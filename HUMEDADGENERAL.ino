

void setup() {
  Serial.begin(9600);

}

void loop(){
  int lectura = analogRead(A1);

  Serial.print("La lectura es: ");
  Serial.println(lectura);

  // lecturas entre 1000 - 1023
if (lectura >= 1000) {
  Serial.println ("›> EL SENSOR ESTA DESCONECTADO O FUERA DEL SUELO <<");
}else if (lectura <1000 && lectura >= 600) {
  Serial.println (">> EL SUELO ESTA SECO <<");
}else if (lectura < 600 && lectura >= 370) {
  Serial.println ("›> EL SUELO ESTA HUMEDO<<");
}else if (lectura < 370) {
  Serial.println ("›> EL SENSOR ESTA EN AGUA<<");
}
delay(1000);

//porcentaje
int lectporcent = map(lectura,1023,0,0,100);
Serial.print ("La humedad es del: ");
Serial.print (lectporcent);
Serial.println ("%");

}
