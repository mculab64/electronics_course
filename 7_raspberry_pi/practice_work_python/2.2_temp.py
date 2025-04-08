#!/usr/bin/env python
import PCF8591 as ADC         # Подключение модуля АЦП (8 бит)
import RPi.GPIO as GPIO       # Подключение модуля GPIO
from time import sleep        # Использование метода sleep из модуля time

ledpin = 21    # GPIO 21

GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setup(ledpin, GPIO.OUT)  # 21 пин настраиваем на вывод
GPIO.setwarnings(False)       # Обработка ошибок

def setup():                  # Функция настройки АЦП
    ADC.setup(0x48)           # Установка адреса АЦП

def loop():                   # Основная программа
    while True:
        analogVal = ADC.read(0)            # Значение с канала ch0 (LM35)
        V = 5 * float(analogVal) / 255     # Перевод в Вольт
        temp = 1000 * V / 10               # Перевод в градусы Цельсия
        print('Температура = {} C'.format(temp))
        sleep(1.0) 
        
        GPIO.output(ledpin, GPIO.HIGH)     # Светодиод включен
        sleep(0.1)
        GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
        sleep(0.1)
        
def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние

if __name__ == '__main__':     # Начало выполнения программы
    try:
        setup()
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()