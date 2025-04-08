#include <Wire.h> // Подключаем библиотеку для работы с I2C

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Сканирование I2C устройств...");
}

void loop() {
  byte error, address;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Устройство найдено по адресу 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  delay(5000);
}
