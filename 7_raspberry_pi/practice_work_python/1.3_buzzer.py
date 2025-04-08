#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

beeppin = 12    # пин 12

def setup():
GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setup(beeppin, GPIO.OUT) # 12 пин настраиваем на вывод
GPIO.output(beeppin, GPIO.LOW)# buzzer выключен
GPIO.setwarnings(False)       # Обработка ошибок

def loop():                            # Основная программа
    while True:
        GPIO.output(beeppin, GPIO.HIGH)
        time.sleep(0.5)
        GPIO.output(beeppin, GPIO.LOW)
        time.sleep(0.5)

def destroy():                         # Функция очистки портов
    GPIO.output(beeppin, GPIO.LOW)     # buzzer выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние    

if __name__ == '__main__':     # Начало выполнения программы
    try:
        setup()
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()