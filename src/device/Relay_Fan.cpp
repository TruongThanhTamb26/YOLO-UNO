#include "Relay_Fan.h"

RelayFanState relayFanState = RELAY_FAN_ON;
RelayFanOnState relayFanOnState = RELAY_ON;

void TaskRelayFan(void *pvParameters)
{
  while (true)
  {
    switch (relayFanState)
    {
    case RELAY_FAN_ON:
      switch (relayFanOnState)
      {
      case RELAY_ON:
        digitalWrite(MY_RELAY, HIGH); // Turn on the relay
        digitalWrite(MY_FAN, LOW);    // Ensure the fan is on
        Serial.println("Relay ON, Fan OFF");
        relayFanOnState = FAN_ON; // Change state
        break;
      case FAN_ON:
        digitalWrite(MY_RELAY, LOW); // Turn off the relay
        digitalWrite(MY_FAN, HIGH);  // Ensure the fan is on
        Serial.println("Relay OFF, Fan ON");
        relayFanOnState = RELAY_ON; // Change state
        break;
      default:
        break;
      }
      relayFanState = RELAY_FAN_OFF; // Change state
      break;
    case RELAY_FAN_OFF:
      digitalWrite(MY_RELAY, LOW); // Turn off the relay
      digitalWrite(MY_FAN, LOW);   // Ensure the fan is off
      Serial.println("Relay OFF, Fan OFF");
      relayFanState = RELAY_FAN_ON; // Change state
      break;
    default:
      break;
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
