#include <SevenSegmentDisplay.h>

unsigned long time;
int sevenSegmentPins[7] = { 2,3,4,5,6,7,8 };
SevenSegmentDisplay sevenSegmentDisplay = SevenSegmentDisplay(sevenSegmentPins);

void setup() {
  time = millis();

  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if (time < 100) {
    sevenSegmentDisplay.showChar('h');
  } else if (time < 200) {
    sevenSegmentDisplay.showChar('e');
  } else if (time < 300) {
    sevenSegmentDisplay.showChar('l');
  } else if (time < 400) {
    sevenSegmentDisplay.showChar('l');
  } else if (time < 500) {
    sevenSegmentDisplay.showChar('o');
  } else if (time < 600) {
    sevenSegmentDisplay.showChar(' ');
  } else if (time < 700) {
    time = millis();
  }
}
