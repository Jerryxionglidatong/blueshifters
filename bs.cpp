#include <ESP32Servo.h>

Servo myServo;
const int TRANSISTOR_PIN = 26
const int SERVO_PIN = 32;

void setup() {
ESP32PWM::allocateTimer(0);
myServo.setPeriodHertz(50);
myServo.attach(SERVO_PIN, 500, 2400);
Serial.begin(115200);
pinMode(TRANSISTOR_PIN, OUTPUT);
digitalWrite(TRANSISTOR_PIN, LOW);
Serial.println("Commands: 1 = ON | 0 = OFF");
}

void loop() {
  myServo.write(80);
  delay(1000);

  myServo.write(95);
    delay(500);
  
  myServo.write(110);
    delay(1000);
  
  myServo.write(95);
    delay(500);

  if (Serial.available()) {
  char cmd = Serial.read();

while (Serial.available()) {
  Serial.read();
}

switch (cmd) {
  case '1':
    digitalWrite(TRANSISTOR_PIN, HIGH);
    Serial.println("ON");
    break;
case '0':
  digitalWrite(TRANSISTOR_PIN, HIGH);
    Serial.println("OFF");
    break;
  default;
    break;
  }
}
}
