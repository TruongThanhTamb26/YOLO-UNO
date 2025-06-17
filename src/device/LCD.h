#ifndef LCD_H
#define LCD_H

#include "globals.h"

extern LCD_I2C lcd; // Default address for many I2C LCDs

void initLCD();

enum LCDState
{
  DISPLAY_HUMIDITY_TEMPERATURE = 0,
  DISPLAY_MOISTURE_LIGHT = 1,
  DISPLAY_DISTANCE = 2,
};

#endif /* LCD_H */