#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    hc06.write(Serial.read());
  }  
}
//Bluetooth connection HM-10 BLE...
//*******************
/
/*
AT //-> OK
AT+NAMENILA10 //-> AT+Set:NILA10
AT+PASS?  //-> AT+Get:000000
AT+PASS123456 //-> AT+Set:123456 //seting pin
AT+ADDR? //-> A810871BFF43 //CHECK MAC ADDRESS (for master only)
AT+IMME1 //->
AT+ROLE1 //-> 1 for Master, 0 for Slave
AT+DISC? //-> Discover slave
AT+CON(MACADDRR)
*/
//************************
