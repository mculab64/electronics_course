#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import time                   # Подключение модуля time

ledpin = 12

GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)  # 12 пин настраиваем на вывод
GPIO.setwarnings(False)       # Обработка ошибок

pwm = GPIO.PWM(ledpin, 1000)     # Установка частоты шим - 1KHz
pwm.start(0)                     # Скважность = 0

def loop():                           # Основная программа
    while True:
        for DC in range(0, 101, 4):   # Уменьшение скважности (%): 0~100
            pwm.ChangeDutyCycle(DC)   # Изменить скважность
            time.sleep(0.1)
        time.sleep(1)
        for DC in range(100, -1, -4): # Уменьшение скважности (%): 100~0
            pwm.ChangeDutyCycle(DC)   # Изменить скважность
            time.sleep(0.1)
        time.sleep(1)

def destroy():                        # Функция очистки портов 
    pwm.stop()                        # Остановка ШИМ
    GPIO.output(ledpin, GPIO.HIGH)    # Светодиод выключен
    GPIO.cleanup()                    # Возврат пинов в исходное состояние

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()