#include "TrafficLight.h"

bool blink = 0;

void TrafficLightTask(void *pvParameters)
{
  while (true)
  {
    if (WiFi.status() != WL_CONNECTED)
    {
      if (blink)
      {
        digitalWrite(MY_TRAFFIC_LIGHT, LOW);
        digitalWrite(MY_RGB, LOW);
        blink = !blink; // Toggle blink state
      }
      else
      {
        digitalWrite(MY_TRAFFIC_LIGHT, HIGH);
        digitalWrite(MY_RGB, HIGH);
        blink = !blink; // Toggle blink state
      }
    }
    else if (!mqttStatus)
    {
      if (blink)
      {
        digitalWrite(MY_TRAFFIC_LIGHT, LOW);
        digitalWrite(MY_RGB, LOW);
        blink = !blink; // Toggle blink state
      }
      else
      {
        digitalWrite(MY_TRAFFIC_LIGHT, HIGH);
        digitalWrite(MY_RGB, LOW);
        blink = !blink; // Toggle blink state
      }
    }
    else
    {
      if (blink)
      {
        digitalWrite(MY_TRAFFIC_LIGHT, LOW);
        digitalWrite(MY_RGB, LOW);
        blink = !blink; // Toggle blink state
      }
      else
      {
        digitalWrite(MY_TRAFFIC_LIGHT, LOW);
        digitalWrite(MY_RGB, HIGH);
        blink = !blink; // Toggle blink state
      }
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
  }
}

void initTrafficLight()
{
  pinMode(MY_TRAFFIC_LIGHT, OUTPUT);
  pinMode(MY_RGB, OUTPUT);
  xTaskCreate(TrafficLightTask, "TrafficLightTask", 2048, NULL, 1, NULL); // Create traffic light task
}