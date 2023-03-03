#include <Arduino.h>
#include <WiFi.h>
#include <Stepper.h>
#include "Settings.h"


#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

#define stepsPerRevolution 2048
#define storeHeight 2048 * 5

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
int currentPosition = 0;

void findHomePosition() {
  Serial.println("Finding home position");
  while(digitalRead(27)) {
    myStepper.step(-stepsPerRevolution / 8);
  }
  Serial.println("Home position: 0");
  currentPosition = 0;
}

void moveUp() {
  while(currentPosition >= 0) {
    myStepper.step(-stepsPerRevolution / 8);
    currentPosition -= stepsPerRevolution / 8;
  }
}

void moveDown() {
  while(currentPosition < storeHeight) {
    myStepper.step(stepsPerRevolution / 8);
    currentPosition += stepsPerRevolution / 8;
  }
}

void setup() {
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
  Serial.println(WiFi.localIP());
  Serial.println(" have FUN :) ");

  myStepper.setSpeed(10);

  pinMode(27, INPUT_PULLUP);
  findHomePosition();
  moveDown();
  moveUp();
}

void loop() {
  delay(500);


}

