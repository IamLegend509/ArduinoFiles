int speed=105 ;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  analogWrite(A0,speed);
}

void loop() {
  
  
  while(speed>=105 && speed<255){
    analogWrite(A0,speed);
    speed+=30;
    fwd();
    delay(500);
  }
  
  while(speed>105 && speed<=255){
    analogWrite(A0,speed);
    speed-=30;
    bck();
    delay(500);
    
  }
  
}

void fwd(){ 
  digitalWrite(3,1);
  digitalWrite(4,0);
  //analogWrite(A0,140);
}
void bck(){
   digitalWrite(3,0);
  digitalWrite(4,1);
  //analogWrite(A0,255);
}