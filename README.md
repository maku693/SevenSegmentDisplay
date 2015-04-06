# SevenSegmentDisplay

An Arduino library to display an ascii character in a seven segment display.

## Usage

### Pins assignment:

```
   _ 1
6 |_| 2 (The middle segment is the pin 7)
5 |_| 3
   4
```
You can use any digital pins. :v:

### Codes:

``` cpp
int sevenSegmentPins[7] = { 2,3,4,5,6,7,8 };
SevenSegmentDisplay sevenSegmentDisplay = SevenSegmentDisplay(sevenSegmentPins);

void setup() {
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  sevenSegmentDisplay.showChar('a'); // Displays “a”
}
```

## Acknowledgements
This library using codes from [ASCIISevenSegment](https://github.com/pvieito/ASCIISevenSegment) by Pedro José Pereira Vieito (@pvieito).

See `ACKNOWLEDGEMENTS` for license informations.