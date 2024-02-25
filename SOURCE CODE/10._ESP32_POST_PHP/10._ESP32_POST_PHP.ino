#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const  char* ssid      = "SNDAY WIFI";      //masukkan ssid
const  char* password  = "abcd1234";  //masukkan password
String namadevice      = "iwancilibur"; //isi dengan nama tanpa spasi

#define RELAY1 18

int indikator=LED_BUILTIN;

void setup () {
   Serial.begin(9600);
   WiFi.begin(ssid, password);
   pinMode (indikator, OUTPUT);
   pinMode (RELAY1,OUTPUT);
   while (WiFi.status() != WL_CONNECTED) {

    //delay(1000);
    Serial.println("Connecting..");
    digitalWrite(indikator,HIGH);
    delay(500);
    digitalWrite(indikator,LOW);
    delay(500);
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("Connected!!!");
    digitalWrite(indikator,HIGH);
  }
  else{
    Serial.println("Connected Failed!!!");
  }

}

void loop() {
  //Pembacaan Sensor
  int getsuhu      =random(25,30);
  int getkelembaban=random(70,85);
  
  //Pengiriman data ke Server
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://192.168.100.226/irciot/data-api.php?namadevice=" + String(namadevice) + 
                                    "&suhu=" + String(getsuhu) + 
                                    "&kelembaban=" + String(getkelembaban));
    int httpCode = http.GET();

    if (httpCode > 0) {
      char json[500];
      String payload = http.getString();
      Serial.println(payload);
      payload.toCharArray(json, 500);
      DynamicJsonDocument doc(JSON_OBJECT_SIZE(7));
      deserializeJson(doc, json);

      String get_waktu         = doc["waktu"];
      String get_nama          = doc["namadevice"];
      String get_suhu          = doc["suhu"];
      String get_kelembapan    = doc["kelembaban"];
      String get_relay1        = doc["relay1"];
      String get_relay2        = doc["relay2"];
  
     Serial.print("Waktu      = ");Serial.println(get_waktu);
     Serial.print("Nama       = ");Serial.println(get_nama);
     Serial.print("Suhu       = ");Serial.println(get_suhu);
     Serial.print("Kelembaban = ");Serial.println(get_kelembapan);
     Serial.print("Relay 1    = ");Serial.println(get_relay1);
     Serial.print("Relay 2    = ");Serial.println(get_relay2);
     Serial.println();

     if(get_relay1 == "1"){
      digitalWrite(RELAY1,HIGH);
      Serial.println("LAMPU 1 NYALA ");
     }else{
      digitalWrite(RELAY1,LOW);
      Serial.println("LAMPU 2 NYALA ");
     }
     delay(1000);
    }
    http.end();
  }
}
