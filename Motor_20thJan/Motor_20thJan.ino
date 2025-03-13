//int speed;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  analogWrite(A0,speed);
}

void loop() {
  fwd();
  delay(1000);

  stop();
  delay(1000);

  bck();
  delay(1000);

  stop();
  delay(1000);
}


void stop(){
  digitalWrite(3,1);
  digitalWrite(4,1);
}