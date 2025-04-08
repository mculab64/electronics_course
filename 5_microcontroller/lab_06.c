unsigned int value;      // Определение переменной

void main() {

  TRISA = 0xFF;          // Выводы AN2 и AN3 аналоговые 
  TRISB = 0x3F;          // RB7 и RB6 настроены на вывод
  TRISD = 0;             // Порт D настроен на вывод
  ADCON1.F4 = 1;         // Установить опорное напряжение с RA3

  do {
    value = ADC_Read(2); // Результат преобразования в value
    PORTD = value;       // 8 разрядов отображены в порт D
    PORTB = value >> 2;  // 2 разряда в битах RB6 и RB7 порта B
  } while (1);           // Бесконечный цикл
}
