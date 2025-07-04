#include "LED.h"

bool ledMode = 0; // Global variable to control LED state

void TaskLED(void *pvParameters)
{
  while (true)
  {
    if (ledMode == 0) // LED OFF
    {
      digitalWrite(MY_LED, LOW);
    }
    else // LED ON
    {
      digitalWrite(MY_LED, HIGH);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 5 second
  }
}

void initLED()
{
  pinMode(MY_LED, OUTPUT);   // Set the LED pin as an output
  digitalWrite(MY_LED, LOW); // Initialize the LED to OFF state
  xTaskCreate(
      TaskLED,   // Function to implement the task
      "TaskLED", // Name of the task
      2048,      // Stack size in words
      NULL,      // Task input parameter
      1,         // Priority of the task
      NULL       // Task handle
  );
}