// Определяем пины для светодиодов
const int led1Pin = 2;  // Пин для 1-го светодиода
const int led2Pin = 3;  // Пин для 2-го светодиода
const int led3Pin = 4;  // Пин для 3-го светодиода

void setup() {
  // Настраиваем пины светодиодов как выходы
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

  // Инициализация последовательного порта
  Serial.begin(9600);

  // Выключаем все светодиоды при старте
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);

  // Выводим инструкцию в монитор порта
  Serial.println("Введите число от 0 до 3:");
  Serial.println("1 - Включить LED 1");
  Serial.println("2 - Включить LED 2");
  Serial.println("3 - Включить LED 3");
  Serial.println("0 - Выключить все LED");
}

void loop() {
  // Проверяем, есть ли данные в последовательном порту
  if (Serial.available() > 0) {
    // Считываем введённое число
    int command = Serial.parseInt();  // Чтение числа из порта

    // Обрабатываем команду
    switch (command) {
      case 0:
        // Выключаем все светодиоды
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        Serial.println("Все светодиоды выключены.");
        break;
      case 1:
        // Включаем первый светодиод
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        Serial.println("Включен LED 1.");
        break;
      case 2:
        // Включаем второй светодиод
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, LOW);
        Serial.println("Включен LED 2.");
        break;
      case 3:
        // Включаем третий светодиод
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, HIGH);
        Serial.println("Включен LED 3.");
        break;
      default:
        // Некорректная команда
        Serial.println("Некорректная ввод. Введите число от 0 до 3.");
        break;
    }
  }
}
