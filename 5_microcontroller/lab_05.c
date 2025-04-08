void main() {

    TRISC = 0;               // Все входы порта C настроены на вывод
    TRISA = 0x0F;            // RA0-RA3 входы порта A настроены на ввод
                             // RA4-RA5 входы порта A настроены на вывод
    CMCON = 0x05;            // Настройка 1-го компаратора
  
    while (1) {
      PORTC.B1 = CMCON.C1OUT;// RB1 настроить на выход C1OUT
      Delay_ms(100);         // Задержка 100 мс
    }
  }
  