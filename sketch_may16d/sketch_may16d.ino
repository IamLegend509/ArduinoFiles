#include <WiFi.h>
#include <esp_now.h>


#define JX1 35
#define JY1 34
#define JX2 32
#define JY2 33
 

uint8_t broadcastAddress[] = {0x8C, 0x4B, 0X14, 0X0C, 0XCA, 0XB4 };
//8C:4B:14:0C:CA:B4

int joystick1X; 
int joystick1Y;
int joystick2X; 
int joystick2Y;
int ValueSendX1;
int ValueSendY1;
int ValueSendX2;
int ValueSendY2;


typedef struct struct_message {
  int a ;
  int b ;
  int c ;
  int d ;
} struct_message;


struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *macAddr, esp_now_send_status_t status)
{
  Serial.print("Last Packet Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
 
   WiFi.mode(WIFI_STA);
 if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
   esp_now_register_send_cb(OnDataSent);
 
 
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
 
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

}

void loop() {

  joystick1X=analogRead(JX1);
  joystick1Y=analogRead(JY1);
  joystick2X=analogRead(JX2);
  joystick2Y=analogRead(JY2);

  ValueSendX1=map(joystick1X,0,4095,0,100);
  ValueSendY1=map(joystick1Y,0,4095,0,100);
  ValueSendX2=map(joystick2X,0,4095,0,100);
  ValueSendY2=map(joystick2Y,0,4095,0,100);
  
  Serial.print("Joystick 1 : X=");
  Serial.print(ValueSendX1);
  Serial.print("  Y=");
  Serial.println(ValueSendY1);
  Serial.print("   ||   Joystick 2 : X=");
  Serial.print(ValueSendX2);
  Serial.print("  Y=");
  Serial.println(ValueSendY2);

  

  
  myData.a=ValueSendX1;
  myData.b=ValueSendY1;
  myData.c=ValueSendX2;
  myData.d=ValueSendY2;


 esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
 delay(1000);
}
