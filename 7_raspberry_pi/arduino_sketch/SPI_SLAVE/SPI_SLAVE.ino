//SLAVE

//определяем пины SPI
#define MOSI_PIN 11 
#define MISO_PIN 12 
#define SCK_PIN  13
#define SS_PIN 10
#define LED_PIN 6

//определяем переменную для получаемого байта
byte recievedByte;

void setup() {
  //обнуляем регистр управления SPI
  SPCR = B00000000;
  //разрешаем работу SPI
  SPCR = (1<<SPE);
   //инициализируем последовательное соединение
  Serial.begin(9600);
  //определяем пины для работы с SPI
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, INPUT);
  pinMode(SS_PIN, INPUT);
}

void loop() {
  //пока пин slave select опущен
  while (digitalRead(SS_PIN)==LOW){
    //принимаем байт и записываем его в переменную
    recievedByte=spi_receive();
    //смотрим в мониторе полученный байт
    Serial.println(recievedByte,DEC);
    if (recievedByte == 0x01)
    { 
      digitalWrite(LED_PIN, HIGH);                      
    }
    if (recievedByte == 0x02)
    { 
      digitalWrite(LED_PIN, LOW);
    }
  }
}

//функция для приема байта
byte spi_receive()
{
  //пока не выставлен флаг окончания передачи, принимаем биты
  while (!(SPSR & (1<<SPIF))){};
  //позвращяем содержимое регистра данных SPI
  return SPDR;                    
}
