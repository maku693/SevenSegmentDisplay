/*
  SevenSegmentDisplay.h
  (c) 2015 Shota HAMADA
  This library is released under MIT License.
*/

#include <Arduino.h>
#include "SevenSegmentDisplay.h"

/*
  Seven segment pins:
     _ 1
  6 |_| 2 (The middle segment is the pin 7)
  5 |_| 3
     4
*/
static const uint8_t sevenSegment[][7] = {
	{ 1,1,1,1,1,1,0 }, // 0
	{ 0,1,1,0,0,0,0 }, // 1
	{ 1,1,0,1,1,0,1 }, // 2
	{ 1,1,1,1,0,0,1 }, // 3
	{ 0,1,1,0,0,1,1 }, // 4
	{ 1,0,1,1,0,1,1 }, // 5
	{ 1,0,1,1,1,1,1 }, // 6
	{ 1,1,1,0,0,0,0 }, // 7
	{ 1,1,1,1,1,1,1 }, // 8
	{ 1,1,1,0,0,1,1 }, // 9
	{ 1,1,1,0,1,1,1 }, // A
	{ 1,1,1,1,1,1,1 }, // B
	{ 1,0,0,1,1,1,0 }, // C
	{ 1,1,1,1,1,1,0 }, // D
	{ 1,0,0,1,1,1,1 }, // E
	{ 1,0,0,0,1,1,1 }, // F
	{ 1,0,1,1,1,1,1 }, // G
	{ 0,1,1,0,1,1,1 }, // H
	{ 0,1,1,0,0,0,0 }, // I
	{ 0,1,1,1,0,0,0 }, // J
	{ 0,1,1,0,1,1,1 }, // K
	{ 0,0,0,1,1,1,0 }, // L
	{ 1,1,1,0,1,1,0 }, // M
	{ 1,1,1,0,1,1,0 }, // N
	{ 1,1,1,1,1,1,0 }, // O
	{ 1,1,0,0,1,1,1 }, // P
	{ 1,1,1,1,1,1,0 }, // Q
	{ 1,1,1,0,1,1,1 }, // R
	{ 1,0,1,1,0,1,1 }, // S
	{ 1,1,1,0,0,0,0 }, // T
	{ 0,1,1,1,1,1,0 }, // U
	{ 0,1,1,1,1,1,0 }, // V
	{ 0,1,1,1,1,1,1 }, // W
	{ 0,1,1,0,1,1,1 }, // X
	{ 0,1,0,0,1,1,1 }, // Y
	{ 1,1,0,1,1,0,1 }, // Z
	{ 0,0,0,0,0,0,0 }, // SPACE
};

SevenSegmentDisplay::SevenSegmentDisplay(int pins[7]) {
	for (int i = 0; i < 7; i++) {
		_pins[i] = pins[i];
	}
}

void SevenSegmentDisplay::showChar(char aChar) {
	int outputDigit;

	if (48 <= aChar && aChar <= 57) { // Numbers
		outputDigit = static_cast<int>(aChar - '0');
	} else if(65 <= aChar && aChar <= 90) { // Capital letters
		outputDigit = static_cast<int>(aChar - 'A' - 10);
	} else if(97 <= aChar && aChar <= 122) { // Low letters
		outputDigit = static_cast<int>(aChar - 'a' - 10);
	} else { // Space
		outputDigit = 37;
	}

	for (int i = 0; i < 7; i++) {
    digitalWrite(_pins[i], sevenSegment[outputDigit][i]);
	}
}
