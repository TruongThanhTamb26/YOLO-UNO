#include "RGB.h"

Adafruit_NeoPixel rgb(4, MY_RGB, NEO_GRBW + NEO_KHZ800);
uint32_t colors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, PURPLE, WHITE, BLACK};
const char *colorNames[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "PURPLE", "WHITE", "BLACK"};
const int numColors = sizeof(colors) / sizeof(colors[0]);

void TaskRGB(void *pvParameters)
{
  while (true)
  {
    for (int i = 0; i < numColors; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        rgb.setPixelColor(j, colors[i]);
      }
      rgb.show();
      Serial.println("Led RGB : " + String(colorNames[i]));
      vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
  }
}

void initRGB()
{
  rgb.begin();
  rgb.setBrightness(50); // Set initial brightness
  xTaskCreate(
      TaskRGB,   // Function to implement the task
      "TaskRGB", // Name of the task
      4096,      // Stack size in words
      NULL,      // Task input parameter
      1,         // Priority of the task
      NULL       // Task handle
  );
}