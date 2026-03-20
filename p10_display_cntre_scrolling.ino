#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char text[] = "VENI RITHIKA";

int x;
int textWidth;

unsigned long prevTime = 0;
int speedDelay = 30;   // smooth scroll

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  // 🔥 Increase brightness by faster refresh
  Timer1.initialize(1200);   // try 1200 / 1000 for more brightness
  Timer1.attachInterrupt(ScanDMD);

  dmd.clearScreen(true);
  dmd.selectFont(SystemFont5x7);

  textWidth = strlen(text) * 6;

  x = 20;   // safe center start
}

void loop() {
  if (millis() - prevTime > speedDelay) {
    prevTime = millis();

    dmd.clearScreen(true);
    dmd.drawString(x, 4, text, strlen(text), GRAPHICS_NORMAL);

    x--;

    if (x < -textWidth) {
      x = 20;
    }
  }
}