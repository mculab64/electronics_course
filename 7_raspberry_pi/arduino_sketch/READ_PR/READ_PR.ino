int light;

void setup()
{
Serial.begin(9600);
}

void loop()
{
     light = analogRead(0);
     Serial.println(light);
     delay(1000);
}

