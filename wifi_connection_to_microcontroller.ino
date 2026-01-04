#include <WiFi.h>

char SSID[] = "POCO M3";
char PASS[] = "1883311M3";

void setup()
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  delay(5000);
  Serial.println(WiFi.localIP());
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi is not connected");
    Serial.println(WiFi.status());
    delay(500);
  }
  Serial.println("WiFi is Connected");
  Serial.println(WiFi.status());
}

void loop()
{

}