#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "key.h"

const byte interruptPin = 2;
volatile byte state = LOW;

void intrpt() {
  state = HIGH;
}

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), intrpt, FALLING);
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if (state) {
    Serial.print("IRQ ");
    Wire.requestFrom(0x20, (uint8_t)1);
    int a = Wire.read();
    Serial.println(a);
    state = LOW;
  }
}
