#include "Relay_Fan.h"

void TaskRelayFan(void *pvParameters)
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
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Toggle every 1 seconds

    // Check the fan state and toggle it
    if (digitalRead(MY_FAN) == LOW)
    {
      digitalWrite(MY_FAN, HIGH); // Turn on the fan
      Serial.println("Fan is ON");
    }
    else
    {
      digitalWrite(MY_FAN, LOW); // Turn off the fan
      Serial.println("Fan is OFF");
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Toggle every second
  }
}

void initRelayFan()
{
  // Initialize the relay pin
  initRelay();
  // Initialize the fan pin
  initFan();
  // Create tasks for relay and fan
  xTaskCreate(
      TaskRelayFan, // Function to implement the task
      "TaskRelay",  // Name of the task
      4096,         // Stack size in words
      NULL,         // Task input parameter
      3,            // Priority of the task
      NULL          // Task handle
  );
}
