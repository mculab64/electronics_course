unsigned short i;

void main() {
  UART1_Init(19200);           // Инициализация модуля USART
                               // (8 бит, 19200 скорость передачи)
  while (1) {
    if (UART1_Data_Ready()) {  // Инициализация модуля USART
      i = UART1_Read();        // Если данные получены,
      UART1_Write(i);          // читать их и отправить обратно
    }
  }
}
