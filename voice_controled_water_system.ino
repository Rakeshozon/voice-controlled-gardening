#include<AFMotor.h>
#include <SoftwareSerial.h>


#define motor 1

AF_DCMotor motor4(4, MOTOR34_1KHZ);


int val;
int Speeed = 255;
  
void setup() {
pinMode(motor,OUTPUT);
 Serial.begin(9600);
}

void loop(){



        if( digitalRead(motor)== HIGH){
        motor4.setSpeed(Speeed);//Define maximum velocity
        motor4.run(FORWARD); //rotate the motor clockwise
        delay(30000);
        motor4.setSpeed(0);
        motor4.run(RELEASE);  
          }
else{
       motor4.setSpeed(0);
       motor4.run(RELEASE);  
}
        }
        
