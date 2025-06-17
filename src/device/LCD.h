#ifndef LCD_H
#define LCD_H

#include "globals.h"

enum LCDState
{
  DISPLAY_TEMP_HUM,
  DISPLAY_MOISTURE
};

extern LCD_I2C lcd; // Default address for many I2C LCDs

void initLCD();

#endif /* LCD_H */