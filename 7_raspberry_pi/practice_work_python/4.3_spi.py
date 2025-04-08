#!/usr/bin/env python
import RPi.GPIO as GPIO        # Подключение модуля GPIO
import spidev                  # Подключение модуля smbus для работы SPI
import time                    # Подключение модуля time
import os                      # Модуль работы с операционной системой

spi = spidev.SpiDev()          # Инициализация SPI
spi.open(0,0)                  # Запуск dev = 0
spi.max_speed_hz = 15200       # Скорость передачи 15.2 kHz

def loop():                    # Основная программа   
    while True:
        send = [0x01]          # Отправка байта 0x01 по SPI
        spi.xfer(send)         
        time.sleep(1.0)
        send = [0x02]          # Отправка байта 0x02 по SPI
        spi.xfer(send)
        time.sleep(1.0)
        # Для чтения данных resp = spi.readbytes(5)

def destroy():                 # Функция очистки портов
    spi.close()                # Остановка dev = 0
    GPIO.cleanup()             # Возврат пинов в исходное состояние
        
if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()