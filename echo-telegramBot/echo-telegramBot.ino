#include "CTBot.h"
CTBot myBot;

String ssid  = "Nama_Wifi";
String pass  = "Pass_Wifi";
String token = "Token";

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
