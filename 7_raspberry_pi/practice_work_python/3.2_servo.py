#!/usr/bin/env python
import RPi.GPIO as GPIO       # Подключение модуля GPIO
import time                   # Подключение модуля time

spin = 17     # пин 17 используется для PWM
Freq = 50     # Частота ШИМ
# Длительность одного импульса (1/Freq) T = 20 мс

imp_dc = [2.5, 5.0, 7.5, 10.0, 12.5,] # Скважность в %
# 0.5 мс -> (0.5/20)*100 = 2.5% -> 0 градусов
# 1.5 мс -> (1.5/20)*100 = 7.5% -> 90 градусов
# 2.5 мс -> (2.5/20)*100 = 12.5% -> 180 градусов

GPIO.setmode(GPIO.BCM)       # Установка режима GPIO.BCM
GPIO.setup(spin, GPIO.OUT)   # 17 пин настраиваем на вывод
GPIO.output(spin, GPIO.LOW)

pwm = GPIO.PWM(spin, Freq)      # Установка частоты шим - 50Hz
pwm.start(7.5)                  # Скважность = 7.5%

def loop():                             # Основная программа
    while True:
        pwm.ChangeDutyCycle(imp_dc[0])  # Угол 0 градусов
        time.sleep(1.0)
        pwm.ChangeDutyCycle(imp_dc[1])  # Угол 45 градусов
        time.sleep(1.0)
        pwm.ChangeDutyCycle(imp_dc[2])  # Угол 90 градусов
        time.sleep(1.0)
        pwm.ChangeDutyCycle(imp_dc[3])  # Угол 135 градусов
        time.sleep(1.0)
        pwm.ChangeDutyCycle(imp_dc[4])  # Угол 180 градусов
        time.sleep(1.0)

def destroy():                        # Функция очистки портов 
    pwm.stop()                        # Остановка ШИМ
    GPIO.cleanup()                    # Возврат пинов в исходное состояние

if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()
