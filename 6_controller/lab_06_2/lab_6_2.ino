#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Подключаем библиотеку для дисплея

// Инициализация дисплея с адресом I2C (обычно 0x27 или 0x3F)
// Адрес 0x27, 16 символов в строке, 2 строки
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Инициализация дисплея
  lcd.begin();
  
  // Включаем подсветку дисплея (если есть)
  lcd.backlight();
  
  // Выводим сообщение на дисплей
  lcd.setCursor(0, 0);        // Устанавливаем курсор в начало
  lcd.print("Hello, World!"); // Выводим текст
}

void loop() {
  // В этом примере loop пустой, так как сообщение выводится в setup()
}
