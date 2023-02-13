#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

String serverName = "url_from_google_script";

unsigned long lastTime = 0;
unsigned long timerDelay = 20000;

int sensor = 0;
int date = 0;

void setup() {
  Serial.begin(115200); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    sensor = (int)random(0, 100);
    date = (int)random(1,31);

    Serial.println("Sensor=" + String(sensor));
    Serial.println("Date=" + String(date));

    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      String serverPath = serverName + "?sensor=" + String(sensor) + "&date=" + String(date);
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}