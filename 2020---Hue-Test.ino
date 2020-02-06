#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

WiFiClient espClient;

const char* ssid = "University of Washington"; // Wifi network SSID
const char* password = ""; // Wifi network password

//String ip = "172.28.219.179"; // Sieg Master IP
//String api_token = "rARKEpLebwXuW01cNVvQbnDEkd2bd56Nj-hpTETB"; // Sieg Master API Token

String ip = "172.28.219.177"; // Red IP
String api_token = "Lht3HgITYDN-96UYm5mkJ4CEjKj20d3siYidcSq-"; // Red API Token

int number = 1;

void setup() {
  Serial.begin(115200);
  setup_wifi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
      delay(1);
      Serial.print("WIFI Disconnected. Attempting reconnection.");
      setup_wifi();
      return; //End this loop cycle if WiFi disconnected
    }
   for (int i = 1; i < 5; i++) {
    changeLight(i, 0, "on", "true", "bri", "254", "hue", "24000", "sat", "200");
    changeLight(i, 0, "on", "false", "bri", "254", "hue", "24000", "sat", "200");
   }
}


void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
  Serial.println("Connected to the WiFi network");
}
