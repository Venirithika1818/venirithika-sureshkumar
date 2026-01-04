#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3bIkRJQz8"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "bhYAmo1cGj4rCveZFfTUCP-WCYdXIJ1T"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char SSID[] = "EIOT";
char PASS[] = "GsBt@333";
char AUTH[] = BLYNK_AUTH_TOKEN;
int  relay[]={1,2,3,4};

BLYNK_WRITE(V0)
{
 int data1 = param.asInt();
 digitalWrite(relay[0], data1); 
}
BLYNK_WRITE(V1)
{
  int data2 = param.asInt();
  digitalWrite(relay[1],data2);
}
BLYNK_WRITE(V2)
{
  int data3 = param.asInt();
  digitalWrite(relay[2],data3);
}
BLYNK_WRITE(V3)
{
  int data4 = param.asInt();
  digitalWrite(relay[3],data4);
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(AUTH, SSID, PASS);
  for(int i=0;i<5;i++){
    pinMode(relay[i],OUTPUT);
  }
  
}

void loop()
{
  Blynk.run();
}
