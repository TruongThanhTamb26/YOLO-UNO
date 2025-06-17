#include "LCD.h"

LCD_I2C lcd(0x21, 16, 2); // Default address for many I2C LCDs

void initLCD()
{
  lcd.begin(false); // Do not call beginWire here, as we already called Wire.begin in setup
  lcd.backlight();
  lcd.clear();
  lcd.print("Henno, ");
  lcd.setCursor(0, 1);
  lcd.print("TRUONGTHANHTAM");
  delay(2000); // Display for 2 seconds
}
