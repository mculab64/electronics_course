#!/usr/bin/env python 3
import smbus       # Подключение модуля smbus для работы I2C
import time        # Подключение модуля time

def setup():                        # Функция настройки АЦП
    address = 0x48                  # Установка адреса АЦП 
    ch = [0x40, 0x41, 0x42, 0x43]   # Определение каналов АЦП 
    bus = smbus.SMBus(1)            # Выбор устройства I2C 

def loop():                            # Основная программа
    while True:
        bus.write_byte(address, ch[0]) # Выбор канала для чтения данных
        value = bus.read_byte(address) # Чтение данных
        print(value)                   # Вывод результата на экран 
        time.sleep(0.1)

def destroy():                         # Функция очистки портов
    GPIO.output(ledpin, GPIO.LOW)      # Светодиод выключен
    GPIO.cleanup()                     # Возврат пинов в исходное состояние
    
if __name__ == '__main__':     # Начало выполнения программы
    try:
        setup()
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()
