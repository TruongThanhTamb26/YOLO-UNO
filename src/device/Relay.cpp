#include "Relay.h"

void TaskRelay(void *pvParameters)
{
  while (true)
  {
    // Check the relay state and toggle it
    if (digitalRead(MY_RELAY) == LOW)
    {
      digitalWrite(MY_RELAY, HIGH); // Turn on the relay
      Serial.println("Relay is ON");
    }
    else
    {
      digitalWrite(MY_RELAY, LOW); // Turn off the relay
      Serial.println("Relay is OFF");
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Toggle every 5 seconds
  }
}

void initRelay()
{
  // Initialize the relay pin
  pinMode(MY_RELAY, OUTPUT);
  xTaskCreate(
      TaskRelay,   // Function to implement the task
      "TaskRelay", // Name of the task
      4096,        // Stack size in words
      NULL,        // Task input parameter
      2,           // Priority of the task
      NULL         // Task handle
  );
}