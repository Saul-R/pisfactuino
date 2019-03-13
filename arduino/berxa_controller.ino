#include "NewPing.h"

// In centimeters / micro_secs
#define PIN_TRIG 12
#define PIN_ECHO 13
#define MAX_DISTANCE 1000

NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

float distance;

void setup() {
  Serial.begin (9600);
}

void print_distance(float distance) {
  Serial.print("Distance: ");
  if (distance >= 400 || distance <= 2) {
    Serial.print(distance);
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }  
}

void loop() { 
  distance = sonar.ping_cm();
  // Send results to Serial Monitor
  print_distance(distance);
  delay(500);
}