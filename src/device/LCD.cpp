#include "LCD.h"

LCD_I2C lcd(0x21, 16, 2); // Default address for many I2C LCDs

void TaskLCD(void *pvParameters)
{
  static LCDState LCDstate = DISPLAY_HUMIDITY_TEMPERATURE; // Start with displaying humidity and temperature
  while (true)
  {
    switch (LCDstate)
    {
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Humidity: ");
      lcd.print(Humidity);
      lcd.print(" %");
      lcd.setCursor(0, 1);
      lcd.print("Temperature: ");
      lcd.print(Temperature);
      lcd.print(" C");
      vTaskDelay(5000 / portTICK_PERIOD_MS); // Wait for 5 seconds before switching back
      LCDstate = DISPLAY_MOISTURE_LIGHT;     // Move to next state
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Moisture: ");
      lcd.print(moisture_value);
      lcd.print(" %");
      lcd.setCursor(0, 1);
      lcd.print("Light: ");
      lcd.print(lightValue);
      lcd.print(" %");
      vTaskDelay(5000 / portTICK_PERIOD_MS); // Wait for 5 seconds before switching back
      LCDstate = DISPLAY_DISTANCE;           // Move to next state
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.print(distanceValue);
      lcd.print(" cm");
      vTaskDelay(5000 / portTICK_PERIOD_MS);   // Wait for 5 seconds before switching back
      LCDstate = DISPLAY_HUMIDITY_TEMPERATURE; // Move back to first state
      break;
    default:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Unknown State");
      break;
    }
  }
}

void initLCD()
{
  lcd.begin(false); // Do not call beginWire here, as we already called Wire.begin in setup
  lcd.backlight();
  lcd.clear();
  lcd.print("Henno, ");
  lcd.setCursor(0, 1);
  lcd.print("TRUONGTHANHTAM");
  delay(2000); // Display for 2 seconds
  xTaskCreate(
      TaskLCD,   // Function to implement the task
      "TaskLCD", // Name of the task
      2048,      // Stack size in words
      NULL,      // Task input parameter
      2,         // Priority of the task
      NULL       // Task handle
  );
}
