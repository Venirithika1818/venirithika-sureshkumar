#include <WiFi.h>
#include <ThingSpeak.h>

char SSID[] = "Rithukumar";
char PASS[] = "rithukumar";
char API[]  = "CNMU1ZCST823MHGQ";
unsigned long ChannelID = 3283577;

WiFiClient client;   



void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  pinMode(25,INPUT);
  delay(500);
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
  int data = analogRead(25);
  Serial.println(data);

  ThingSpeak.writeField(ChannelID,1,data, API);
  
  delay(1000);
  
}