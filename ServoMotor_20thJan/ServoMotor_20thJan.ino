#include <Servo.h>
Servo name;
void setup() {
  name.attach(9);
}

void loop() {
  //int i=105;
  for(int i=75;i<=500;i+=5){
  name.write(0);
  delay(i);
  name.write(90);
  delay(i);
  }
}
