#include "esp32-hal.h"
#include <Arduino.h>

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
const char* topic = "AKM_RUSSIAN_ROULATE";

const int ledPin1 = 2;
const int ledPin2 = 4;
const int ledPin3 = 5;

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '1') {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

  } else if ((char)payload[0] == '2') {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);

  } else if ((char)payload[0] == '3') {
    for (int i = 0; i < 2; i++){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      delay(500);
      digitalWrite(ledPin3, LOW);
      delay(500);
    }
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("esp32-client")) {
      client.subscribe(topic);
    } else {
      delay(1000);
    }
  }
}

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}