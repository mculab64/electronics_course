#define LED_PIN 13
byte num = 0;

void setup(){
  Serial.begin(9600);
}
 
void loop(){
  if (Serial.available())  {
    num = Serial.read();
    Serial.print("number: ");
    Serial.println(num, DEC);

    if (num == 1)
    { 
      digitalWrite(LED_PIN, HIGH);                      
    }

    else if (num == 2)
    { 
      digitalWrite(LED_PIN, LOW);                      
    }
  }
}
