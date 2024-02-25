#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid        = "Mamangcoffee";
const char* password    = "mamangkopi2021";
const char* mqtt_server = "broker.hivemq.com";
const char* client_id   = "iwan/esp32/001";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;


void setup() {
  WiFi.disconnect();
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);  
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Terima Data: ");
  Serial.print(topic);
  Serial.print(". isi Pesan: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "iwan/relay1") {
    Serial.print("Status : ");
    if(messageTemp == "on"){
      Serial.println("LAMPU ON");
    }
    else if(messageTemp == "off"){
      Serial.println("LAMPU OFF");
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(client_id)) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("iwan/relay1"); //Masukan Sesuai dengan Data yang di Subscribe
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(500);

  // BACA DATA SENSOR
  int dataku = random(0, 100);

  // CONVERT DATA TO STRING
  String dataku_pub = String(dataku);

  // PUBLISH TO MQTT BROKER
  client.publish("iwan/data", dataku_pub.c_str()); 

  //PRINT TO SERIAL
  Serial.print ("DATA :"); Serial.print (dataku_pub.c_str());
  Serial.println(); 
}
