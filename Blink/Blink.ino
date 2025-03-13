int Pot;
int Del;
void setup() {
  // put your setup code here, to run once:
  pinMode(A1,INPUT); //pinMode tells the pin number and its function
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Pot= analogRead(A1);                //angelHead(A1)
  Del=map(Pot,0,1024,0,2000);  //Manipulates Input      //Map Takes data from a certain range and works between that 
  //Jisme value daalne hai--> 2nd var = Map(1st var, 1st low, 1st High, 2nd low, 2nd high)
  digitalWrite(13, HIGH); //DigitalWrite tells the pinNumber called and its high or low value
  delay(Del);  //
  digitalWrite(13, LOW);
  delay(Del);

}

//USR--->Pot---->Microprocessor---->LED