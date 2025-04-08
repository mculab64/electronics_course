#include <Wire.h>  // Подключаем библиотеку для работы с I2C

const int slaveAddress = 0x08;  // Адрес Arduino Nano

void setup() {
  Serial.begin(9600);  // Инициализация последовательного порта
  Wire.begin();        // Инициализация I2C в режиме Master
}

void loop() {
  // Запрашиваем данные от Slave
  Wire.requestFrom(slaveAddress, 2);  // Запрос 2 байт данных

  // Чтение данных
  if (Wire.available() == 2) {
    byte tempInt = Wire.read();   // Целая часть температуры
    byte tempFrac = Wire.read();  // Дробная часть температуры

    // Вычисление температуры
    float temperature = tempInt + (tempFrac / 100.0);

    // Вывод температуры в монитор порта
    Serial.print("Температура: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

delay(1000); // Задержка между запросами
}
