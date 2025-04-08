int num_1 = 1;
int num_2 = 2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println(num_1);
  delay(500);
  Serial.println(num_2);
  delay(500);     
}
