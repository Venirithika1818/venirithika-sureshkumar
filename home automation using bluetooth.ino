# include<SoftwareSerial.h>
SoftwareSerial bluethooth (7,8);
int relay_pin1=12;
int relay_pin2=13;
int relay_pin3=4;
void setup() {
  Serial.begin(9600);
  bluethooth.begin(9600);
  pinMode(relay_pin1,OUTPUT);
  pinMode(relay_pin2,OUTPUT);
  pinMode(relay_pin3,OUTPUT);
}

void loop() {
  if(bluethooth.available()>0)
  {
    char data=bluethooth.read();
    Serial.print(data);
  switch(data)
  {
    case 'a':digitalWrite(relay_pin1,0);
    break;
    case 'b':digitalWrite(relay_pin1,1);
    break;
    case 'c':digitalWrite(relay_pin2,0);
    break;
    case 'd':digitalWrite(relay_pin2,1);
    break;
    case 'e':digitalWrite(relay_pin3,0);
    break;
    case 'f':digitalWrite(relay_pin3,1);
    break;
  }
  
  }    
}
