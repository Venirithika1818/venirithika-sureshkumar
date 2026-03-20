#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

// Interrupt for refreshing display
void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  Timer1.initialize(5000);
  Timer1.attachInterrupt(ScanDMD);

  dmd.clearScreen(true);
  dmd.selectFont(SystemFont5x7);
}

void loop() {
  // Scroll text across 2 displays (64 width)
  for (int i = 0; i < 64; i++) {
    dmd.clearScreen(true);
    dmd.drawString(64 - i, 0, "HELLO", 5, GRAPHICS_NORMAL);
    delay(100);
  }
}