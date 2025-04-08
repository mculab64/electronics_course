// Определяем пин, к которому подключен датчик LM35
const int sensorPin = A0;  // Аналоговый пин A0

void setup() {
  // Инициализируем последовательный порт
  Serial.begin(9600);
}

void loop() {
  // Читаем аналоговое значение с датчика
  int sensorValue = analogRead(sensorPin);

  // Преобразуем аналоговое значение в напряжение
  float voltage = (sensorValue * 5.0) / 1023;

  // Преобразуем напряжение в температуру (в градусах Цельсия)
  float temperature = (voltage / 0.01);

  // Отображаем температуру в последовательном порту
  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000); // Задержка в 1 секунду
}
