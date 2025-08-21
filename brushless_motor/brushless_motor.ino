#include <ESP32Servo.h>

Servo ESC1;
Servo ESC2;

void setup() {
  ESC1.attach(26, 1000, 2000);
  ESC2.attach(27, 1000, 2000);
  delay(2000); 
}

void loop() {
  for (int speed = 0; speed <= 180; speed++) {
    ESC1.write(speed);
    delay(20);
  }

  for (int speed = 180; speed >= 0; speed--) {
    ESC1.write(speed);
    delay(20);
  }

  for (int speed = 0; speed <= 180; speed++) {
    ESC2.write(speed);
    delay(20);
  }

  for (int speed = 180; speed >= 0; speed--) {
    ESC2.write(speed);
    delay(20);
  }
}
