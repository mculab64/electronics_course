#include <Wire.h> // Подключаем библиотеку для работы с I2C

const int lmPin = A0;         // Пин для датчика LM35
const int i2cAddress = 0x08;  // Адрес Arduino Nano на шине I2C

void setup() {
  // Инициализация I2C в режиме Slave с указанным адресом
  Wire.begin(i2cAddress);

  // Регистрация обработчика события запроса данных от Master
  Wire.onRequest(requestEvent);
}

void loop() {
  // Основной цикл пустой, так как данные отправляются по запросу
}

// Функция для обработки запроса данных от Master
void requestEvent() {
  // Считываем аналоговое значение с датчика LM35
  int analogValue = analogRead(lmPin);

  // Преобразуем аналоговое значение в напряжение (в вольтах)
  float voltage = analogValue * (5.0 / 1023.0);

  // Переводим напряжение в температуру (LM35 выдает 10 мВ на градус Цельсия)
  float temperature = (voltage * 0.01);

  // Отправляем температуру как два байта (целая и дробная части)
  byte tempInt = (byte)temperature;  // Целая часть температуры
  byte tempFrac = (byte)((temperature - tempInt) * 100);  // Дробная часть температуры

  Wire.write(tempInt);   // Отправляем целую часть
  Wire.write(tempFrac);  // Отправляем дробную часть
}
