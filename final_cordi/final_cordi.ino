#include<SoftwareSerial.h>
#include <ArduinoJson.h>
//#include <PubSubClient.h>
//#include <ESP8266WiFi.h>
//#include <ESP8266WiFiMulti.h>
//#include <stdio.h>
String macaddress = "";
String tempmac="";
String value = "";
SoftwareSerial sserial(4,5);
SoftwareSerial nodemcu(6,7);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
sserial.begin(9600);
//nodemcu.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(sserial.available()>=19)
{
  
    for(int i=0;i<16;i++){
      byte skip = sserial.read();
      if(i>4){
        tempmac=String(skip);
      macaddress=macaddress+tempmac;
//        Serial.print(skip,HEX);
//      Serial.print(",");
      }
    }
    
    int val_10 = sserial.read();
    int val_1 = sserial.read();
    val_10=val_10-48;
    val_1 = val_1 -48;
    String ue=String(val_10);
    String ee=String(val_1);
    value=ue+ee;
//    Serial.print(val_10);
//    Serial.print(val_1);

   val_1 = sserial.read();

//  StaticJsonDocument<1000> doc;
// 
// doc["macaddress"]=macaddress;
// doc["value"]=value;
//  
//  serializeJson(doc,nodemcu);



   
   Serial.print("MAC ADDRESS : ");
   Serial.print(macaddress);
   Serial.print(" Value : ");
  
   Serial.print(value);
   Serial.println();
    tempmac="";
    macaddress="";
 
}


}
