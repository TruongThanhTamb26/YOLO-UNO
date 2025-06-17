#include "LCD.h"

LCD_I2C lcd(Wire, 0x21, 16, 2); // Default address for many I2C LCDs

void TaskLCD(void *pvParameters)
{
  while (true)
  {
    lcd.clear();
    lcd.print("Henno, World!");
    lcd.setCursor(0, 1);
    lcd.print("ESP32 LCD Test");
    vTaskDelay(2000 / portTICK_PERIOD_MS); // Update every 2 seconds
  }
}

void initLCD()
{
  lcd.begin(false); // Do not call beginWire here, as we already called Wire.begin in setup
  lcd.backlight();
  xTaskCreate(
      TaskLCD,   // Function to implement the task
      "TaskLCD", // Name of the task
      4096,      // Stack size in words
      NULL,      // Task input parameter
      1,         // Priority of the task
      NULL       // Task handle
  );
}
