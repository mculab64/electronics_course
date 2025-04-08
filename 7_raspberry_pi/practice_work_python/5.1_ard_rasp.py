#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import serial                 # Подключение модуля serial
import time                   # Подключение модуля time

ledpin = 21    # пин 21

GPIO.setmode(GPIO.BCM)         # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)   # 21 пин настраиваем на вывод

# Настройка serial порта через USB
ser = serial.Serial("/dev/ttyUSB1", 9600)

num_1 = [0x01]
num_2 = [0x02]
           
def loop():                            # Основная программа
    while True:
        ser.write(num_1)               # Запись данных в порт
        print('Свет включен')
        GPIO.output(ledpin, GPIO.HIGH) # Светодиод включен
        time.sleep(0.5)

        ser.write(num_2)               # Запись данных в порт
        print('Свет выключен')
        GPIO.output(ledpin, GPIO.LOW)  # Светодиод выключен
        time.sleep(0.5)

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние   

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()


