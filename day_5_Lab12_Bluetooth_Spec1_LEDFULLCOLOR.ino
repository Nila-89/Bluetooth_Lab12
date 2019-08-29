#include <SoftwareSerial.h>
#define BT_TX 2
#define BT_RX 3
#define LedG 10
#define LedR 9
#define LedB 11

SoftwareSerial mySerial(BT_TX, BT_RX);
String myString = "";

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LedG, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedB, OUTPUT);
}

void loop() {
  while (mySerial.available()) {
    char myChar = (char)mySerial.read();
    myString += myChar;
    delay(5);
  }

  if (!myString.equals("")) {
    Serial.println("Received : " + myString);
    LED();
    myString = "";
  }
}

void LED() {
  if (myString == "R") {
    Serial.println("RED LED ON");
    analogWrite(LedR, 0);
    analogWrite(LedG, 255);
    analogWrite(LedB, 255);
  } else if (myString == "G") {
    Serial.println("GREEN LED ON");
    analogWrite(LedR, 255);
    analogWrite(LedG, 0);
    analogWrite(LedB, 255);
  } else if (myString == "B") {
    Serial.println("BLUE LED ON");
    analogWrite(LedR, 255);
    analogWrite(LedG, 255);
    analogWrite(LedB, 0);
  } 
  
  else if (myString == "AUTO") {
    Serial.println("ALL LED ON");
    analogWrite(LedR, 0);    
    analogWrite(LedG, 0);    
    analogWrite(LedB, 0);
    delay(800);
    
    analogWrite(LedR, 0);    
    analogWrite(LedG, 255);    
    analogWrite(LedB, 255);
    delay(800);

    analogWrite(LedR, 255);    
    analogWrite(LedG, 0);    
    analogWrite(LedB, 255);
    delay(800);

    analogWrite(LedR, 255);    
    analogWrite(LedG, 255);    
    analogWrite(LedB, 0);
    delay(800);   

     analogWrite(LedR, 255);    
    analogWrite(LedG, 255);    
    analogWrite(LedB, 255);
    delay(800);    
  }
}
