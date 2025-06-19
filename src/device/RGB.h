#ifndef _RGB_H_
#define _RGB_H_

#include "globals.h"

extern Adafruit_NeoPixel rgb;

const uint32_t RED = rgb.Color(255, 0, 0);
const uint32_t ORANGE = rgb.Color(255, 165, 0);
const uint32_t YELLOW = rgb.Color(255, 255, 0);
const uint32_t GREEN = rgb.Color(0, 255, 0);
const uint32_t BLUE = rgb.Color(0, 0, 255);
const uint32_t INDIGO = rgb.Color(75, 0, 130);
const uint32_t PURPLE = rgb.Color(148, 0, 211);
const uint32_t WHITE = rgb.Color(255, 255, 255);
const uint32_t BLACK = rgb.Color(0, 0, 0);

enum RGBColor
{
  COLOR_RED,
  COLOR_ORANGE,
  COLOR_YELLOW,
  COLOR_GREEN,
  COLOR_BLUE,
  COLOR_INDIGO,
  COLOR_PURPLE,
  COLOR_WHITE,
  COLOR_BLACK
};

extern RGBColor currentColor;

extern bool Auto;

void initRGB();

#endif // _RGB_H_