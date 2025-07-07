#ifndef neopixel_h
#define neopixel_h

#include "globals.h"

extern Adafruit_NeoPixel neopixel;

enum configColor
{
  BLINK_WHITE,
  BLINK_RED,
  BLINK_YELLOW,
  BLINK_GREEN
};

void initNeopixel();

#endif //