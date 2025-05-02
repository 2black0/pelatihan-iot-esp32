#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>

const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

AsyncWebServer server(80);
ESPDash dashboard(&server); 

Card button(&dashboard, BUTTON_CARD, "Test Button");
Card slider(&dashboard, SLIDER_CARD, "Test Slider", "", 0, 255);
Card temperature(&dashboard, TEMPERATURE_CARD, "Temperature", "°C");
Card humidity(&dashboard, HUMIDITY_CARD, "Humidity", "%");

uint8_t led = BUILTIN_LED;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.printf("WiFi Failed!\n");
      return;
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  pinMode(led, OUTPUT);
	digitalWrite(led, LOW);

  button.attachCallback([&](bool value){
    Serial.println("Button Triggered: "+String((value)?"true":"false"));
    button.update(value);
    digitalWrite(led, value);
    dashboard.sendUpdates();
  });

  slider.attachCallback([&](int value){
    Serial.println("Slider Triggered: "+String(value));
    slider.update(value);
    dashboard.sendUpdates();
  });

  server.begin();
}

void loop() {
  temperature.update((int)random(0, 50));
  humidity.update((int)random(0, 100));
  dashboard.sendUpdates();
  delay(3000);
}