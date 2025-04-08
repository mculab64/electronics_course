// Определяем пины для кнопки и светодиодов
const int buttonPin = 8;             // Пин кнопки
const int ledPins[] = {2, 3, 4, 5};  // Пины светодиодов

// Переменная для хранения количества нажатий
int buttonPressCount = 0;
// Переменная для хранения предыдущего состояния кнопки
int lastButtonState = HIGH;

void setup() {
  // Настраиваем пины светодиодов на вывод
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Настраиваем пин кнопки на ввод
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Считываем текущее состояние кнопки
  int buttonState = digitalRead(buttonPin);

  // Проверяем, изменилось ли состояние кнопки
  if (buttonState != lastButtonState) {
    // Если кнопка нажата (состояние HIGH)
    if (buttonState == LOW) {
      // Увеличиваем счётчик нажатий
      buttonPressCount++;

      // Ограничиваем счётчик до 15 (максимальное значение для 4 бит)
      if (buttonPressCount > 15) {
        buttonPressCount = 0;
      }
      // Обновляем состояние светодиодов
      updateLEDs(buttonPressCount);
    }
    // Задержка для устранения дребезга контактов
    delay(50);
  }
  // Сохраняем текущее состояние кнопки для следующего цикла
  lastButtonState = buttonState;
}
// Функция для обновления состояния светодиодов
void updateLEDs(int count) {
  for (int i = 0; i < 4; i++) {
    // Устанавливаем состояние светодиода в соответствии с битом числа
   digitalWrite(ledPins[i], bitRead(count, i));
  }
}
