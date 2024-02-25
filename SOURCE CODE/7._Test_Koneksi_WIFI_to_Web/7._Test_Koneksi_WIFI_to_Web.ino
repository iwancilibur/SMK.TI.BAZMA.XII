#include <WiFi.h>
#include <HTTPClient.h>

// WiFi Parameters
const char* ssid = "Mamangcoffee";
const char* password = "mamangkopi2021";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected!");
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("https://test.inteknus.asia/index.php");
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      payload.trim();
      Serial.print("Jawaban: ");Serial.println(payload);
    }else{
       Serial.println("Menunggu Jawaban... ");
    }

    delay(1000);
    http.end();   //Close connection
  }
}
