#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import smbus                  # Подключение модуля smbus для работы I2C
from time import sleep        # Использование метода sleep из модуля time
import os                     # Модуль работы с операционной системой

bus = smbus.SMBus(1)          # Установка адреса устройства
address = 0x04                # Выбор адреса устройства I2C

def read_data():              # Функция чтения данных 
    reading = float(bus.read_byte(address))
    print(reading)

def write_data():             # Функция записи данных 
    bus.write_byte(address, ord('l'))
    
def loop():                            # Основная программа
    while True:
        print('Получаем данные по i2c')
        read_data()
        sleep(0.5)                     # Пауза длительностью 0.5 сек. 
        print('Отправляем данные по i2c')
        write_data()
        sleep(0.5)                     # Пауза длительностью 0.5 сек.

def destroy():                         # Функция очистки портов
    GPIO.cleanup()                     # Возврат пинов в исходное состояние  
        
if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()