#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
int sensor=A0;
int buzzer=8;
int led=7;
void setup() 
{
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  


}

void loop() {
  int data=analogRead(sensor);
  Serial.print("moister_level : ");
  Serial.println(data); 
  delay(1000);
  if(data>=600)
  {
    lcd.setCursor(1,1);
    lcd.print("soil_is_dry : ");
    lcd.println("needs_water");
    digitalWrite(led,1);
    delay(1000);
    digitalWrite(led,0);
  }
  else if(data>600&&data<600)
  {
    lcd.setCursor(1,1);
    lcd.print("partially_dry : ");
    lcd.println("in_good_condion");
  }
  else
  {
    lcd.setCursor(1,1);
    lcd.print("very_wet : ");
    lcd.println("too_much_of_water");
    digitalWrite(buzzer,1);
    delay(1000);
    digitalWrite(buzzer,0);

  }

}
