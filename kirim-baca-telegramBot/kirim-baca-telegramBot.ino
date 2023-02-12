#include "CTBot.h"
CTBot myBot;

String ssid = "Nama_Wifi";
String pass = "Pass_Wifi";
String token = "Token";

uint8_t led = BUILTIN_LED;				
int sensorA = 25;
int sensorB = 89;
String reply;

void setup() {
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");
	myBot.wifiConnect(ssid, pass);
	myBot.setTelegramToken(token);

	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");

	pinMode(led, OUTPUT);
	digitalWrite(led, LOW);

}

void loop() {
	TBMessage msg;

	if (CTBotMessageText == myBot.getNewMessage(msg)) {
		if (msg.text.equalsIgnoreCase("/ledoff")) {
			digitalWrite(led, LOW);
			myBot.sendMessage(msg.sender.id, "LED OFF");
		}
		else if (msg.text.equalsIgnoreCase("/ledon")) {
			digitalWrite(led, HIGH);
			myBot.sendMessage(msg.sender.id, "LED ON");
		}
    else if (msg.text.equalsIgnoreCase("/sensora")) {
			reply = (String)"Data sensor A = " + (String)sensorA;
			myBot.sendMessage(msg.sender.id, reply);
		}
    else if (msg.text.equalsIgnoreCase("/sensorb")) {
			reply = (String)"Data sensor B = " + (String)sensorB;
			myBot.sendMessage(msg.sender.id, reply);
		}
		else {
			reply = (String)"Welcome " + msg.sender.username + ".\n";
      reply += "/ledon : Perintah untuk menyalakan LED\n";
      reply += "/ledoff : Perintah untuk mematikan LED\n";
      reply += "/sensora : Perintah untuk membaca sensor A\n";
      reply += "/sensorb : Perintah untuk membaca sensor B\n";
			myBot.sendMessage(msg.sender.id, reply);
		}
	}
	delay(500);
}