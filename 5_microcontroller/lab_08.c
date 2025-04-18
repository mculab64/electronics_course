void main() {

    TRISB = 0;              // Все входы порта B настроены на вывод
    PORTB = 0;              // Начальное состояние порта B
    PORTD = 0;              // Все входы порта D настроены на вывод
    TRISD = 0;              // Начальное состояние порта D
    TRISA = 0xFF;           // Все входы порта A настроены на вход
  
    PORTD = EEPROM_Read(5);     // Чтение EEPROM памяти по адресу 5
  
    do {
      PORTB = PORTB++;          // Увеличить порт B на единицу
      Delay_ms(100);
      if (PORTA.B2) {
        EEPROM_Write(5, PORTB); // Если MEMO нажата, сохраняем в PORTB
        PORTD = EEPROM_Read(5); // Чтение записанных данных
        do;
        while (PORTA.B2);       // Оставаться в цикле при нажатии кнопки
      }
    }
    while (1);                  // Бесконечный цикл
  }
  