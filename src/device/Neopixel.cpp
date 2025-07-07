#include "Neopixel.h"

Adafruit_NeoPixel neopixel(1, MY_NEOPIXEL, NEO_GRBW + NEO_KHZ800);
configColor currentNeopixel = BLINK_WHITE; // Default color

bool blink = 0;

void TaskNeopixel(void *pvParameters)
{
  while (true)
  {
    switch (currentNeopixel)
    {
    case BLINK_WHITE:
      if (blink)
      {
        neopixel.setPixelColor(0, neopixel.Color(255, 255, 255, 0)); // White
      }
      else
      {
        neopixel.setPixelColor(0, neopixel.Color(0, 0, 0, 0)); // Off
      }
      if (info)
      {
        currentNeopixel = BLINK_RED;
      }
      break;
    case BLINK_RED:
      if (blink)
      {
        neopixel.setPixelColor(0, neopixel.Color(255, 0, 0, 0)); // Red
      }
      else
      {
        neopixel.setPixelColor(0, neopixel.Color(0, 0, 0, 0)); // Off
      }
      if (WiFi.status() == WL_CONNECTED)
      {
        currentNeopixel = BLINK_YELLOW; // Change to green if WiFi is connected
      }
      break;
    case BLINK_YELLOW:
      if (blink)
      {
        neopixel.setPixelColor(0, neopixel.Color(255, 255, 0, 0)); // Yellow
      }
      else
      {
        neopixel.setPixelColor(0, neopixel.Color(0, 0, 0, 0)); // Off
      }
      if (WiFi.status() != WL_CONNECTED)
      {
        currentNeopixel = BLINK_RED;
      }
      else if (mqttStatus)
      {
        currentNeopixel = BLINK_GREEN; // Change to green if MQTT is connected
      }
      break;
    case BLINK_GREEN:
      neopixel.setPixelColor(0, neopixel.Color(0, 255, 0, 0)); // Green
      if (WiFi.status() != WL_CONNECTED)
      {
        currentNeopixel = BLINK_RED;
      }
      else if (!mqttStatus)
      {
        currentNeopixel = BLINK_YELLOW;
      }
      break;
    }
    neopixel.show(); // Update the Neopixel
    blink = !blink;  // Toggle blink state
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void initNeopixel()
{
  neopixel.begin();
  neopixel.setBrightness(50); // Set initial brightness
  xTaskCreate(
      TaskNeopixel, "TaskNeopixel", 2048, NULL, 1, NULL); // Create the Neopixel task
}