#include <WiFi.h>
#include <ThingSpeak.h>

char SSID[] = "EIOT";
char PASS[] = "GsBt@333";
char API[]  = "EJQ738TI6DCZCZJD";
unsigned long ChannelID = 3214638;

WiFiClient client;  

#define  PIR 18
#define  LDR 19

void setup() {
  Serial.begin(9600);
  pinMode(PIR,INPUT);
  pinMode(LDR,INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  delay(5000);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi is not connected");
    Serial.println(WiFi.status());
    delay(500);
  }
  Serial.println("WiFi is Connected");
  Serial.println(WiFi.status());

  ThingSpeak.begin(client);
}

void loop() {
  int data1 = digitalRead(PIR);   
  int data2 = analogRead(LDR);    

  Serial.print("PIR: ");
  Serial.print(data1);
  Serial.print("  | LDR: ");
  Serial.println(data2);

  ThingSpeak.writeField(ChannelID,1,data1, API);
  ThingSpeak.writeField(ChannelID,2,data2, API);
}
