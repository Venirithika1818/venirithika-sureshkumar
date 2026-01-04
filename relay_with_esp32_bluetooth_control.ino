#include "BluetoothSerial.h"   
BluetoothSerial serialBT;  
int sensor=13;    

void setup() 
{
  Serial.begin(9600);      
  serialBT.begin("twail");  
  pinMode(sensor, INPUT);
}

void loop() 
{
  int data = digitalRead(sensor);
  Serial.print(data);
  if(data==0){
    serialBT.println("sensed");
    delay(1000);
 }
  else if(data==1){
    serialBT.println(" not sensed");
    delay(1000);
  }
}
