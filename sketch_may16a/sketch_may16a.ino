/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-joystick
 */

#define VRX_PIN  13 // ESP32 pin GPIO36 (ADC0) connected to VRX pin
#define VRY_PIN  12 // ESP32 pin GPIO39 (ADC0) connected to VRY pin

int valueX = 0; // to store the X-axis value
int valueY = 0; // to store the Y-axis value
int ValueSendX;
int ValueSendY;

void setup() {
  Serial.begin(9600) ;
}

void loop() {
  // read X and Y analog values
  valueX = analogRead(VRX_PIN);
  valueY = analogRead(VRY_PIN);

  ValueSendX=map(valueX,0,4095,0,100);
  ValueSendY=map(valueY,0,4095,0,100);
  
  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(ValueSendX);
  Serial.print(", y = ");
  Serial.println(ValueSendY);
  delay(200);
}
