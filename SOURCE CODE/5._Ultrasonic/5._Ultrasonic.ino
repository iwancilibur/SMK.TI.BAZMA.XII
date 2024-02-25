#include <NewPing.h>

#define TRIGGER_PIN 26 
#define ECHO_PIN    27 
#define MAX_DISTANCE 100 // Maximum distance 400-500cm.

NewPing cm(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(9600);
}

void loop() {
 int getjarak=cm.ping_cm();
 Serial.print("Jarak :"); Serial.print(getjarak); Serial.print(" cm");
 Serial.println();
 delay(200);
}
