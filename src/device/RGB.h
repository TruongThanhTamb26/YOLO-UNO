#ifndef _RGB_H_
#define _RGB_H_

#include "globals.h"

const uint32_t OFF = Adafruit_NeoPixel::Color(0, 0, 0);
const uint32_t RED = Adafruit_NeoPixel::Color(255, 0, 0);
const uint32_t ORANGE = Adafruit_NeoPixel::Color(255, 102, 0);
const uint32_t YELLOW = Adafruit_NeoPixel::Color(255, 255, 0);
const uint32_t GREEN = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t BLUE = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t INDIGO = Adafruit_NeoPixel::Color(75, 0, 130);
const uint32_t PURPLE = Adafruit_NeoPixel::Color(128, 0, 128);
const uint32_t WHITE = Adafruit_NeoPixel::Color(255, 255, 255);
const uint32_t BLACK = Adafruit_NeoPixel::Color(0, 0, 0);

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