#include <FastLED.h>

#define LED_PIN     8
#define NUM_LEDS    1
#define BRIGHTNESS  50
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(1000);
  
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(1000);
}
