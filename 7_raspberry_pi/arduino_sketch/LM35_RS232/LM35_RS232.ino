int ledPin = 13;
boolean ledOn = false;
 
void setup(){
  Serial.begin(9600);   // Скорость работы порта
}
 
void loop(){
  
int  val = analogRead(A0);         // Чтение

float temp = (val*5.0/1024)*100;
  Serial.println(temp);
  delay(1000);
}
