unsigned short current_duty, old_duty;  // Определение переменных

void initMain() {                       // Функция настройки портов

    PORTA = 0;
    TRISA = 0;
    PORTB = 255;
    TRISB = 255;
    PORTC = 0;
    TRISC = 0;
    PWM1_Init(5000);              // Инициализация PWM модуля (5KHz)
}
 
void main() {                     // Начальное состояние current_duty
    initMain();
    current_duty = 100;
    old_duty = 0;                 // Сбросить переменную old_duty
    PWM1_Start();                 // Запуск PWM1 модуля
    PWM1_Set_Duty(current_duty);  // Установка параметров PWM1 модуля

    while (1) {
        if (RB0_bit == 0)         // Кнопка, подключенная к RB0 нажата
            current_duty++;       // Увеличить параметр current_duty

        if (RB1_bit == 0)         // Кнопка, подключенная к RB1 нажата
            current_duty--;       // Уменьшить параметр current_duty

// Если current_duty и old_duty не равны
        if (old_duty != current_duty) { 
            PWM1_Set_Duty(current_duty); // Новые параметрами PWM
            old_duty = current_duty;     // Cохранить новое значение
            PORTA = old_duty;            // Показать его в порте B
        }
        Delay_ms(200);
    }
}
