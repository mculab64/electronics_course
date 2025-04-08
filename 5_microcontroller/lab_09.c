void Tone1() {
    Sound_Play(659, 250); // Частота = 659Hz, длительность = 250 мсек
  }
  void Tone2() {
    Sound_Play(698, 250); // Частота = 698Hz, длительность = 250 мсек
  }
  void Tone3() {
    Sound_Play(784, 250); // Частота = 784Hz, длительность = 250 мсек
  }
  
  void Melody1() {            // Мелодия 1
    Tone1();  Tone2();  Tone3();
    Tone3();  Tone1();  Tone2();
    Tone3();  Tone3();  Tone1();
    Tone2();  Tone3();  Tone1();
    Tone2();  Tone3();  Tone3();
    Tone1();  Tone2();  Tone3();
    Tone3();  Tone3();  Tone2();
    Tone2();  Tone1();
  }
  void ToneA() {
    Sound_Play(880, 50);       // Тон A
  }
  void ToneC() {
    Sound_Play(1046, 50);      // Тон С
  }
  void ToneE() {
    Sound_Play(1318, 50);      // Тон E
  }
  void Melody2() {             // Мелодия 2
    unsigned short i;
    for (i = 9; i > 0; i--) {
      ToneA();
      ToneC();
      ToneE();
    }
  }
  void main() {
    TRISB = 0xF0;                    // Входы RB7-RB4 настроены на вход,
                                     // RB3 на вывод
    Sound_Init( & PORTB, 3);
    Sound_Play(1000, 500);
  
    while (1) {
      if (Button( & PORTB, 7, 1, 1)) // RB7 генерирует Тон1
        Tone1();
      while (PORTB & 0x80);
      if (Button( & PORTB, 6, 1, 1)) // RB6 генерирует Тон2
        Tone2();
      while (PORTB & 0x40);
      if (Button( & PORTB, 5, 1, 1)) // RB5 генерирует Мелодию 2
        Melody2();
      while (PORTB & 0x20);
      if (Button( & PORTB, 4, 1, 1)) // RB4 генерирует Мелодию 1
        Melody1();
      while (PORTB & 0x10);          // Ждём нажатия кнопки
    }
  }
  