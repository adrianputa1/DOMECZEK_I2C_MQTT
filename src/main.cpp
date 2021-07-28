#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>

const byte interruptPin = 2;
volatile byte state = LOW;

void intrpt() {
  state = HIGH;
}

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), intrpt, FALLING);
}

void loop() {

}
