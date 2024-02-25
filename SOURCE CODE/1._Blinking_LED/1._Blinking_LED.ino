#define LED 5

void setup() {
  Serial.begin(9600);
  pinMode (LED,OUTPUT);
}

void loop() {
  Serial.println("LED NYALA");
  digitalWrite(LED,HIGH);
  delay(1000);
  Serial.println("LED MATI");
  digitalWrite(LED,LOW);
  delay(1000);
}
