#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL370VmkJdO"
#define BLYNK_TEMPLATE_NAME "gas sensor"
#define BLYNK_AUTH_TOKEN "WlOjOB_elo6GfgKlMoNhWdxunENKUAQq"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char SSID[] = "EIOT";
char PASS[] = "GsBt@333";
char AUTH[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void sensor()
{
  int data = analogRead(21);
  Blynk.virtualWrite(V0, data);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(AUTH, SSID, PASS);  
  pinMode(21,OUTPUT);
  timer.setInterval(2000L, sensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  Blynk.logEvent("sensor_value","gas value is low");
}
