#!/usr/bin/env python
import RPi.GPIO as GPIO

ledpin = 12    # пин 12 - светодиод
btnpin = 16    # пин 16 - кнопка

def setup():                       # Функция настройки портов
    GPIO.setmode(GPIO.BCM)         # Установка режима GPIO.BCM
    GPIO.setup(ledpin, GPIO.OUT)   # 12 пин настраиваем на вывод
    # 16 пин на ввод и подтянут через резистор к уровню 3.3В
    GPIO.setup(btnpin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    GPIO.output(ledpin, GPIO.LOW)  # Светодиод выключен
    GPIO.setwarnings(False)        # Обработка ошибок

def loop():                        # Основная программа
    while True:
        if GPIO.input(btnpin) == GPIO.LOW: # Проверка нажатия кнопки
            print('Светодиод включен')
            GPIO.output(ledpin, GPIO.LOW)  # Светодиод включен
        else:
            print('Светодиод выключен')
            GPIO.output(ledpin, GPIO.HIGH) # Светодиод выключен

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние   

if __name__ == '__main__':     # Начало выполнения программы
    try:
        setup()
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()