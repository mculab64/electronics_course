#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import requests               # Модуль для работы с http
import serial                 # Подключение модуля serial
from time import sleep        # Использование метода sleep bp модуля time

temp = 0
none = 'none'
ledpin = 21 # GPIO 21

GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)  # 21 пин настраиваем на вывод

# Настройка serial порта через USB
ser = serial.Serial("/dev/ttyUSB0", 9600)

def loop():                            # Основная программа
    while True:
        temp = ser.readline()          # Чтение данных из порта
        #temp = int(temp)              # byte -> int
        print(temp)
        
        # Отправка данных на сервер по http
        payload = {'voltage_1': temp, 'voltage_2': none}
        r = requests.get('http://metananobio.ru/temp/temp.php', params=payload)

        print('Данные отправлены')
        GPIO.output(ledpin, GPIO.HIGH) # Светодиод включен
        sleep(0.1)                     # Пауза длительностью 0.5 сек.
        GPIO.output(ledpin, GPIO.LOW)  # Светодиод выключен
        sleep(0.1)                     # Пауза длительностью 0.5 сек.
        
        sleep(5.0)

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние 

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()
