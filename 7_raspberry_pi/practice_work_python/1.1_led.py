#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
from time import sleep        # Использование метода sleep из модуля time

ledpin = 12                   # пин 12

GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)  # 12 пин настраиваем на вывод
GPIO.setwarnings(False)       # Обработка ошибок

def loop():                            # Основная программа
    while True:
        print('Светодиод включен')
        GPIO.output(12, GPIO.HIGH)     # Светодиод включен
        sleep(0.5)                     # Пауза длительностью 0.5 сек.
        print('Светодиод выключен')
        GPIO.output(12, GPIO.LOW)      # Светодиод выключен
        sleep(0.5)                     # Пауза длительностью 0.5 сек.

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()