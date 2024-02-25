#define BLYNK_TEMPLATE_ID           "TMPL6A7LVJJv7"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "COT86q6M_hNAtIR18uC5inYZcuCmgU1P"

#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "SNDAY WIFI";
char pass[] = "abcd1234";

BlynkTimer timer;

#define RELAY1 18
#define RELAY2 19

BLYNK_WRITE(V0)
{
  int relay1 = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, relay1);
  if(relay1 == 1){
    digitalWrite(RELAY1,HIGH);
  }else{
    digitalWrite(RELAY1,LOW);
  }
}

BLYNK_WRITE(V4)
{
  int relay2 = param.asInt();

  // Update state
  Blynk.virtualWrite(V4, relay2);
  if(relay2 == 1){
    digitalWrite(RELAY2,HIGH);
  }else{
    digitalWrite(RELAY2,LOW);
  }
}


BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

#include <DHT.h>
#define DHTPIN 25 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void myTimerEvent()
{
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();

  Blynk.virtualWrite(V5, suhu);
  Blynk.virtualWrite(V6, kelembaban);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  dht.begin(); 
  pinMode (RELAY1,OUTPUT);
  pinMode (RELAY2,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
