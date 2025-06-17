#include "HCSR04.h"

Ultrasonic ultrasonic(MY_TRIG, MY_ECHO);

void TaskHCSR04(void *pvParameters)
{
  while (true)
  {

    Serial.print("1: ");
    Serial.print(ultrasonic.read());
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