#include "HCSR04.h"

int distanceValue = 0; // Global variable to store the distance value

Ultrasonic ultrasonic(MY_TRIG, MY_ECHO);

void TaskHCSR04(void *pvParameters)
{
  while (true)
  {
    distanceValue = ultrasonic.read();

    Serial.print("1: ");
    Serial.print(distanceValue);
    Serial.println(" cm");

    Serial.println("---");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}

void initHCSR04()
{

  xTaskCreate(
      TaskHCSR04,   // Function to implement the task
      "TaskHCSR04", // Name of the task
      4096,         // Stack size in words
      NULL,         // Task input parameter
      2,            // Priority of the task
      NULL          // Task handle
  );
}