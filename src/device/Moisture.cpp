#include "Moisture.h"

GravitySoilMoistureSensor gravity_sensor;

void TaskMoisture(void *pvParameters)
{
  while (true)
  {
    uint16_t moisture_value = gravity_sensor.Read();
    Serial.println("Moisture Value: " + String(moisture_value));
    publishData("Moisture", String(moisture_value));
    vTaskDelay(5000 / portTICK_PERIOD_MS); // Update every 5 seconds
  }
}

void initMoisture()
{
  gravity_sensor.Setup(MY_MOISTURE);

  xTaskCreate(
      TaskMoisture,   // Function to implement the task
      "TaskMoisture", // Name of the task
      4096,           // Stack size in words
      NULL,           // Task input parameter
      2,              // Priority of the task
      NULL            // Task handle
  );
}