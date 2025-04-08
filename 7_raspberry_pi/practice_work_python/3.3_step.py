import RPi.GPIO as GPIO # Подключение модуля GPIO
import time             # Подключение модуля time

delay = 0.005           # Временная задержка 5 мс
pause = 0.5             # Временная задержка 500 мс
steps = 500             # Число шагов

GPIO.setmode(GPIO.BCM)        # Установка режима GPIO.BCM
GPIO.setwarnings(False)       # Обработка ошибок

# Определение GPIO выводов для IN1-4 (uln2003)
coil_N_1_pin = 16 # GPIO 16
coil_N_2_pin = 19 # GPIO 19
coil_N_3_pin = 20 # GPIO 20
coil_N_4_pin = 26 # GPIO 26

# Настройка GPIO на вывод 
GPIO.setup(coil_N_1_pin, GPIO.OUT)
GPIO.setup(coil_N_2_pin, GPIO.OUT)
GPIO.setup(coil_N_3_pin, GPIO.OUT)
GPIO.setup(coil_N_4_pin, GPIO.OUT)

# Функция для определения шага
def setStep(n1, n2, n3, n4):
     GPIO.output(coil_N_1_pin, n1)
     GPIO.output(coil_N_2_pin, n2)
     GPIO.output(coil_N_3_pin, n3)   
     GPIO.output(coil_N_4_pin, n4) 

# Функция для определения вращения
def move():
    # Шаговый режим прямой
    for i in range(0, steps):  
        setStep(1,0,0,0)
        time.sleep(delay)
        setStep(0,1,0,0)
        time.sleep(delay)
        setStep(0,0,1,0)
        time.sleep(delay)
        setStep(0,0,0,1)
        time.sleep(delay)
    print('Вращение по часовой стрелке') 
    # Шаговый режим реверсный
    for i in range(0, steps):
        setStep(0,0,0,1)
        time.sleep(delay)
        setStep(0,0,1,0)
        time.sleep(delay)
        setStep(0,1,0,0)
        time.sleep(delay)
        setStep(1,0,0,0)
        time.sleep(delay)
    print('Вращение против часовой стрелке')

def destroy():                 # Функция очистки портов 
    GPIO.cleanup()             # Возврат пинов в исходное состояние

def loop():                    # Основная программа
    while True:
        move()
        time.sleep(pause)      # Пауза длительностью 0.5 сек.
     
if __name__ == '__main__':     # Начало выполнения программы
    try:
        loop()
    except KeyboardInterrupt:  # Прерывание при нажатии 'Ctrl+C'
        destroy()     
     
     