#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import serial                 # Подключение модуля serial
import time                   # Подключение модуля time
import os                     # Модуль работы с операционной системой

ledpin = 21    # пин 21

GPIO.setmode(GPIO.BCM)         # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)   # 21 пин настраиваем на вывод

# Настройка serial порта через AMA0
ser = serial.Serial("/dev/ttyAMA0", 9600)
           
def loop():                        # Основная программа
    while True:
        num = ser.readline()       # Чтение данных из порта
        num = int(num)             # byte -> int
        print(num)
        
        if num == 1:                       # Проверка освещения
            print('Свет включен')
            GPIO.output(ledpin, GPIO.HIGH) # Светодиод включен
            #time.sleep(0.5)
        elif num == 2:
            print('Свет выключен')
            GPIO.output(ledpin, GPIO.LOW)  # Светодиод выключен
            #time.sleep(0.5)

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние   

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy() 


