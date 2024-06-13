#include <LedMatrix.h>

const int DIN = 8;
const int CS = 9;
const int CLK = 10;
const int xPin = A0; 
const int yPin = A1;
int yValue;
int xValue;
int xPos = 0; 
int yPos = 0;
int xSad=random(1,8);
int ySad=random(1,8);
LedMatrix matrix(DIN, CLK, CS); 

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  matrix.wakeup();
  matrix.clear();
  matrix.setIntensity(10);
  matrix.setRotation(2); 

}

void loop() {
 if(xPos==xSad && yPos==ySad){ 
     ySad=random(0,8);
     xSad=random(0,8);
   }
  
 xValue=map(analogRead(A0), 0, 1023, 511, -512); 
 yValue=map(analogRead(A1), 0, 1023, -511, 512);
  
 if(xValue>60 && xPos<7){
     xPos=xPos+1;
   }
 else if(xValue<-60 && xPos>0){
    xPos=xPos-1;
  }
 else if(yValue>60 && yPos<7){	
    yPos=yPos+1;
  }
  else if(yValue<-60 && yPos>0){ 
    yPos=yPos-1;
  }
  matrix.clear();
  matrix.on(xSad, ySad);
  matrix.on(xPos, yPos);
  delay(100);
}
