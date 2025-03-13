//#include "LiquidCrystal_I2C.h"
#include "AFMotor.h"
//LiquidCrystal_I2C lcd(0x27, 16, 2);  
#define rightLS A1;
#define leftLS A0;
byte echoPinR =A3;
byte trigpinR=A2;
byte echoPinL =A4;
byte trigPinL =A5;


byte trigPinR =A4 ; 
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);                 

long durationR;
long durationL;

long distanceR;
long distanceL; 


void setup()
{
  //lcd.init();
                      
  //lcd.backlight();
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT); 
  pinMode(echoPinL, INPUT); 
  motor1.setSpeed(185);
  motor2.setSpeed(185);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  Serial.begin(9600);
  delay(500);
}


void loop()
{
  /*lcd.home();
  lcd.print("LS"); 
  lcd.setCursor(12, 0);
  lcd.print("RS"); 
  lcd.setCursor(0, 1);*/

  lSensor();
  rSensor();
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  if(!analogRead(rightLS)<=350 && !analogRead(leftLS)<=350)
  {
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);  
  else if(analogRead(rightLS)<=350 && analogRead(leftLS)<=350){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
   if(distanceL<=15 /*|| distanceR<=15*/){
     motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
    if(distanceR<=15){
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      
    }
    delay(25);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }

  else{
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  Serial.print("Distance - Left: ");
  Serial.print(distanceL);
  Serial.print(" cm, Right: ");
  Serial.print(distanceR);
  Serial.println(" cm");
  delay(50);
}

void leftTurn()
{
  if((distanceL<=15 && distanceL>=2)&& (distanceR>=15 && distanceR<=400))
  {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motot3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
}

void rightTurn()
{
  if((distanceR<=15 && distanceR>=2)&& (distanceL>=15 && distanceL<=400))
  {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motot3.run(FORWARD);
    motor4.run(FORWARD);
  }
}

void standard()
{
  if(distanceR==distanceL){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motot3.run(FORWARD);
    motor4.run(FORWARD);
  }
}

void withIR(){
  
}


void lSensor()
{
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2); 


  digitalWrite(trigPinL, HIGH); 
  delayMicroseconds(10); 


  digitalWrite(trigPinL, LOW);


  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL * 0.0344 / 2;
  //lcd.print(distanceL);
  //lcd.setCursor(12,1);
  Serial.print(distanceL);
  Serial.print("\n");
}

void rSensor()
{
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2); 


  digitalWrite(trigPinR, HIGH); 
  delayMicroseconds(10); 


  digitalWrite(trigPinR, LOW);


  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR * 0.0344 / 2;
  //lcd.print(distanceR);
  //Serial.print(distanceR);
  Serial.print("\n");
}




//A5 Purple Ltrig
//A4 blue Lecho
//A1 white Rtrig
//A0 grey Recho


