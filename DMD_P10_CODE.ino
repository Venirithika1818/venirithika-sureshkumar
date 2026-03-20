#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

// Interrupt function for refreshing display
void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  // Start Timer for scanning
  Timer1.initialize(5000);
  Timer1.attachInterrupt(ScanDMD);

  dmd.clearScreen(true);
  dmd.selectFont(SystemFont5x7);
}

void loop() {
  // Scroll text
  for (int i = 0; i < 32; i++) {
    dmd.clearScreen(true);
    dmd.drawString(32 - i, 0, "HELLO", 5, GRAPHICS_NORMAL);
    delay(100);
  }
}