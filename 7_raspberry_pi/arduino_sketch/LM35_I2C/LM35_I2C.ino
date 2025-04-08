#include <Wire.h>
 
int SLAVE_ADDRESS = 0x04;
int ledPin = 13;
boolean ledOn = false;
 
void setup(){
  Serial.begin(9600);            // Скорость работы порта
  Wire.begin(SLAVE_ADDRESS);
}
 
void loop(){
  
int  val = analogRead(A0);       // чтение
byte  temp = (val*5.0/1024)*100; // в градусы Цельсия
  Serial.print(" temp = ");
  Serial.println(temp);
  Wire.write(temp);
  delay(1000);
}
