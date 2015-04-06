/*
  SevenSegmentDisplay.h
  (c) 2015 Shota HAMADA
  This library is released under MIT License.
*/

#ifndef SevenSegmentDisplay_h
#define SevenSegmentDisplay_h

#include <stdint.h>

class SevenSegmentDisplay {
	public:
		SevenSegmentDisplay(int pins[7]);
		void showChar(char aChar);
	private:
		int _pins[7];
};

#endif
