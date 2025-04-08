#include <SPI.h>  // Подключаем библиотеку для работы с SPI

const int lmPin = A0;    // Пин датчика LM35
const int ssPin = 10;    // Пин для выбора Slave (SS)

volatile byte receivedData = 0;
volatile bool dataReceived = false; // Флаг получения данных

void setup() {
  // Настраиваем пин SS как вход
  pinMode(ssPin, INPUT);

  // Инициализация SPI в режиме Slave
  SPCR |= bit(SPE);  // Включаем SPI
  SPCR |= bit(SPIE); // Включаем прерывания SPI

  // Включаем глобальные прерывания
  sei();
}

void loop() {
  // Если данные получены
  if (dataReceived) {
    // Считываем аналоговое значение с датчика LM35
    int analogValue = analogRead(lmPin);

    // Преобразуем аналоговое значение в напряжение (в вольтах)
    float voltage = analogValue * (5.0 / 1023.0);

    float temperature = voltage * 100.0;

    // Отправляем температуру как два байта (целая и дробная части)
    byte tempInt = (byte)temperature;  // Целая часть температуры
    byte tempFrac = (byte)((temperature - tempInt) * 100);  // Дробная часть температуры

    // Отправляем данные Master устройству
    SPI.transfer(tempInt);   // Отправляем целую часть
    SPI.transfer(tempFrac);  // Отправляем дробную часть

    // Сбрасываем флаг получения данных
    dataReceived = false;
  }
}

// Обработчик прерывания SPI
ISR(SPI_STC_vect) {
  // Чтение полученных данных
  receivedData = SPDR;
  dataReceived = true;
}
