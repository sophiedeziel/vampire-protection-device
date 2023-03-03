#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Settings.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.printf("Connecting to %s\n", ssid);
  if (String(WiFi.SSID()) != String(ssid)) {
    WiFi.begin(ssid, password);
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected! With IP ");
  Serial.print(WiFi.localIP());
  Serial.println(" have FUN :) ");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  delay(10000);
}
