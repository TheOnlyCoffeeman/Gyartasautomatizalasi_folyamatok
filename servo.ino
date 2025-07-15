#include <Servo.h>

Servo servo1;  // Pin 8
Servo servo2;  // Pin 9

void servoSetup(){
  Serial.begin(115200);
  servo1.attach(8);
  servo2.attach(9);
}

void moveHomePos(){
  servo1.write(90);
  servo2.write(90);
}

void moveServos(){
  
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int comma = input.indexOf(',');
    if (comma > 0) {
      int angle1 = constrain(input.substring(0, comma).toInt(), 0, 180);
      int angle2 = constrain(input.substring(comma + 1).toInt(), 0, 180);
      servo1.write(angle1);
      servo2.write(angle2);
      Serial.println(String(angle1) + "," + String(angle2));
    }
  }
}
void setup() {
  servoSetup();
  moveHomePos();
}

void loop() {
  moveServos();  
}
