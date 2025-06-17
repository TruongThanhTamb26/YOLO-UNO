#include "HCSR04.h"

HCSR04Sensor hcsr04;

void getValueHCSR04()
{
  double *distances = hcsr04.measureDistanceCm();

  // Add error checking before using the pointer
  if (distances != NULL && *distances > 0)
  {
    Serial.println(String(*distances) + " cm");
    publishData("Distance", String(*distances));
  }
  else
  {
    Serial.println("HCSR04 reading error or out of range");
    publishData("Distance", "error");
  }
}

void TaskHCSR04(void *pvParameters)
{
  while (true)
  {
    getValueHCSR04();
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}

void initHCSR04()
{
  hcsr04.begin(MY_TRIG, MY_ECHO);

  xTaskCreate(
      TaskHCSR04,   // Function to implement the task
      "TaskHCSR04", // Name of the task
      4096,         // Stack size in words
      NULL,         // Task input parameter
      2,            // Priority of the task
      NULL          // Task handle
  );
}