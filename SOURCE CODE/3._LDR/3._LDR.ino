#define LDR 25

void setup() {
  Serial.begin(9600);
  pinMode (LDR,INPUT);
}

void loop() {
  int BacaLDR = analogRead(LDR);
  Serial.println(BacaLDR);
  delay(100);
}
