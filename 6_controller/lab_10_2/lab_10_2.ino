#include <SPI.h>  // Подключаем библиотеку для работы с SPI

const int ssPin = 10;  // Пин для выбора Slave (SS)

void setup() {
  Serial.begin(9600);        // Инициализация последовательного порта
  pinMode(ssPin, OUTPUT);    // Настраиваем пин SS как выход
  digitalWrite(ssPin, HIGH); // Деактивируем Slave
  SPI.begin();               // Инициализация SPI в режиме Master
}

void loop() {
  // Активируем Slave
  digitalWrite(ssPin, LOW);

  // Запрашиваем данные от Slave устройства
  byte tempInt = SPI.transfer(0);   // Получаем целую часть температуры
  byte tempFrac = SPI.transfer(0);  // Получаем дробную часть температуры

  // Деактивируем Slave
  digitalWrite(ssPin, HIGH);

  // Вычисление температуры
  float temperature = tempInt + (tempFrac / 100.0);

  // Вывод температуры в монитор порта
  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);  // Задержка между запросами
}
