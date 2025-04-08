#include <Servo.h>  // Подключаем библиотеку для сервопривода

// Определяем пины для сервопривода и кнопки
const int servoPin = 2;  // Пин сервопривода
const int buttonPin = 8; // Пин кнопки

// Создаем объект для управления сервоприводом
Servo myServo;

// Переменная для хранения текущего угла сервопривода
int angle = 0;

// Переменная для хранения предыдущего состояния кнопки
int lastButtonState = HIGH;

void setup() {
  // Настраиваем пин кнопки как вход
  pinMode(buttonPin, INPUT);

  // Привязываем сервопривод к указанному пину
  myServo.attach(servoPin);

  // Устанавливаем начальное положение сервопривода (0 градусов)
  myServo.write(angle);
}

void loop() {
  // Считываем текущее состояние кнопки
  int buttonState = digitalRead(buttonPin);

  // Проверяем, изменилось ли состояние кнопки
  if (buttonState != lastButtonState) {
    // Если кнопка нажата (состояние HIGH)
    if (buttonState == LOW) {
      // Поворачиваем сервопривод на 90 градусов
      angle = 90;
      myServo.write(angle);
    } else {
      // Возвращаем сервопривод в исходное положение (0 градусов)
      angle = 0;
      myServo.write(angle);
    }

    // Задержка для устранения дребезга контактов
    delay(50); // Задержка в 50 мсек
  }

  // Сохраняем текущее состояние кнопки для следующего цикла
  lastButtonState = buttonState;
}
