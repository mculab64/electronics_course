// Контакт 4 для подключения светодиода
const int LED = 4;

void setup() {
  // Инициализация цифрового пина с номером 4
  pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, HIGH); Светодиод включен, LED ON
    delay(i);
    digitalWrite(LED, LOW); Светодиод выключен, LED OFF
    delay(i);
}
