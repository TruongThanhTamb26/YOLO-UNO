#include "RGB.h"

Adafruit_NeoPixel rgb = Adafruit_NeoPixel(4, MY_RGB, NEO_GRB + NEO_KHZ800);
uint32_t colors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, PURPLE, WHITE, BLACK};

bool Auto = true;
RGBColor currentColor = COLOR_RED; // Start with OFF color

void TaskRGB(void *pvParameters)
{
  while (true)
  {
    switch (currentColor)
    {
    case COLOR_RED:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_ORANGE; // Change to the next color
      }
      else
      {
        currentColor = COLOR_RED; // Stay RED if not in Auto mode
      }
      break;
    case COLOR_ORANGE:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_YELLOW; // Change to the next color
      }
      else
      {
        currentColor = COLOR_ORANGE; // Stay ORANGE if not in Auto mode
      }
      break;
    case COLOR_YELLOW:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_GREEN; // Change to the next color
      }
      else
      {
        currentColor = COLOR_YELLOW; // Stay YELLOW if not in Auto mode
      }
      break;
    case COLOR_GREEN:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_BLUE; // Change to the next color
      }
      else
      {
        currentColor = COLOR_GREEN; // Stay GREEN if not in Auto mode
      }
      break;
    case COLOR_BLUE:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_INDIGO; // Change to the next color
      }
      else
      {
        currentColor = COLOR_BLUE; // Stay BLUE if not in Auto mode
      }
      break;
    case COLOR_INDIGO:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_PURPLE; // Change to the next color
      }
      else
      {
        currentColor = COLOR_INDIGO; // Stay INDIGO if not in Auto mode
      }
      break;
    case COLOR_PURPLE:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_WHITE; // Change to the next color
      }
      else
      {
        currentColor = COLOR_PURPLE; // Stay PURPLE if not in Auto mode
      }
      break;
    case COLOR_WHITE:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_BLACK; // Change to the next color
      }
      else
      {
        currentColor = COLOR_WHITE; // Stay WHITE if not in Auto mode
      }
      break;
    case COLOR_BLACK:
      rgb.clear(); // Clear previous colors
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : " + String(currentColor));
      if (Auto)
      {
        currentColor = COLOR_RED; // Change to the next color
      }
      else
      {
        currentColor = COLOR_BLACK; // Stay BLACK if not in Auto mode
      }
      break;
    default:
      // If an unknown color is encountered, reset to OFF
      for (int i = 0; i < 4; i++)
        rgb.setPixelColor(i, colors[currentColor]); // Set the current color
      rgb.show();
      Serial.println("Led RGB : OFF");
      currentColor = COLOR_RED; // Reset to OFF
      break;
    }
    vTaskDelay(2000 / portTICK_PERIOD_MS);
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