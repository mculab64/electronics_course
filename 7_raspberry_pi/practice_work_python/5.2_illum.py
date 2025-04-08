#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import serial                 # Подключение модуля serial
import time                   # Подключение модуля time

ledpin = 21    # пин 21

GPIO.setmode(GPIO.BCM)         # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)   # 21 пин настраиваем на вывод

ser = serial.Serial(           # Настройка serial порта
    port='/dev/ttyACM0',
    baudrate = 9600,
    timeout=1
)
           
def loop():                        # Основная программа
    while True:
        phres = ser.readline()     # Чтение данных из порта
        phres = int(phres)         # byte -> int
        print(phres)
        
        if phres > 100:                    # Проверка освещения
            print('Свет включен')
            GPIO.output(ledpin, GPIO.HIGH) # Светодиод включен
            time.sleep(0.5)
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