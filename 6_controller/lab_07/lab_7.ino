const int outputPin = 8;     // Пин, на котором будет генерироваться сигнал
const int frequency = 1000;  // Частота сигнала в герцах (1 кГц)

void setup() {
  // Настройка пина как выхода
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // Генерация сигнала заданной частоты
  tone(outputPin, frequency); // Генерация сигнала

  // Бесконечный цикл, так как сигнал генерируется непрерывно
  while (true) {
   // Можно добавить другие действия, если необходимо
  }
}
