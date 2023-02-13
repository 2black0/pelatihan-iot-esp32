#include "CTBot.h"
CTBot myBot;

const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

String token = "token-get-from-telegram-botfather";

void setup() {
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");

	myBot.wifiConnect(ssid, pass);
	myBot.setTelegramToken(token);
	
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");
}

void loop() {
	TBMessage msg;
	if (CTBotMessageText == myBot.getNewMessage(msg))
		myBot.sendMessage(msg.sender.id, msg.text);
	delay(500);
}
