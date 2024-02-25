#define BUTTON 15

void setup() {
  Serial.begin(9600);
  pinMode (BUTTON,INPUT);
}

void loop() {
  int BacaButton = digitalRead(BUTTON);
  Serial.println(BacaButton);

  if(BacaButton == 1){
    Serial.println("Button Ditekan!");
  }else{
    Serial.println("Button Dilepas!");
  }
  delay(100);
}
