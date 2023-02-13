#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

const char* mqtt_server = "192.168.1.14";

WiFiClient espClient;
PubSubClient client(espClient);

long now = millis();
long lastMeasure = 0;

uint8_t led = BUILTIN_LED;

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
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if(topic=="room/lamp"){
      Serial.print("Changing Room lamp to ");
      if(messageTemp == "on"){
        digitalWrite(led, HIGH);
        Serial.print("On");
      }
      else if(messageTemp == "off"){
        digitalWrite(led, LOW);
        Serial.print("Off");
      }
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");  
      client.subscribe("room/lamp");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
	Serial.begin(115200);
  pinMode(led, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP32Client");

  now = millis();
  if (now - lastMeasure > 30000) {
    lastMeasure = now;
    int h = (int)random(0, 100);
    int t = (int)random(0, 100);

    char tempString[8];
    dtostrf(t, 1, 2, tempString);
    char humString[8];
    dtostrf(h, 1, 2, humString);

    client.publish("room/temperature", tempString);
    client.publish("room/humidity", humString);
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t Temperature: ");
    Serial.print(t);
    Serial.println(" *C ");
  }
} 
