// Контакт 4 для подключения светодиода
const int LED = 4;

// Контакт 2 для подключения кнопки
const int BUTTON = 2;

void setup() {
  // Сконфигурировать контакт светодиода как выход
  pinMode(LED, OUTPUT);

  // Сконфигурировать контакт кнопки как вход
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED, HIGH);  // Если кнопка нажата (LOW), LED ON
  } else {
    digitalWrite(LED, LOW);   // Если кнопка не нажата (HIGH), LED OFF
  }
}
