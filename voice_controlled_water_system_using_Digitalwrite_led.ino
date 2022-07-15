#include <SoftwareSerial.h>
#define MotorPin 13
SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;


  
void setup() {
   BT.begin(9600);
 Serial.begin(9600);
}
void loop(){
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  
  }  
     if (readvoice.length() > 0) {
        Serial.println(readvoice);

        if(readvoice == "water the plants" || readvoice == 'w'){
           digitalWrite(MotorPin , HIGH);
           delay(5000);
           digitalWrite(MotorPin , LOW);
           }
           if(readvoice == "stop" || readvoice == 's'){
            digitalWrite(MotorPin , LOW);
            }
            readvoice = "";
  } 
}
