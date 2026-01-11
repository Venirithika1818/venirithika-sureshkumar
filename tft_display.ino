#include <Adafruit_GFX.h>      
#include <Adafruit_ST7735.h>   
#include <SPI.h>

#define TFT_CS     10   
#define TFT_RST    9    
#define TFT_DC     8    

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  Serial.println("TFT Display Test");

  tft.initR(INITR_BLACKTAB); 
  tft.setRotation(1);        

  tft.fillScreen(ST77XX_BLACK);


  tft.setTextColor(ST77XX_WHITE); 
  tft.setTextSize(2);             
  tft.setCursor(10, 30);          

  tft.println("Hello");
}

void loop() {
  
}
