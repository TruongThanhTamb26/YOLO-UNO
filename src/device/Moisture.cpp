#include "Moisture.h"

GravitySoilMoistureSensor gravity_sensor; // Declare the Gravity Soil Moisture Sensor object

void TaskMoisture(void *pvParameters)
{
  while (true)
  {
    uint16_t moisture_value = gravity_sensor.Read();
    moisture_value = map(moisture_value, 0, 3500, 0, 100); // Map to percentage
    // LCD
    lcd.setCursor(0, 0);
    lcd.print("Moisture:");
    lcd.print(moisture_value);
    lcd.print(" %");
    // Serial
    Serial.println("Moisture Value: " + String(moisture_value) + "%");
    // MQTT
    publishData("Moisture", String(moisture_value));
    vTaskDelay(5000 / portTICK_PERIOD_MS); // Update every 5 seconds
  }
}

void initMoisture()
{
  gravity_sensor.Setup(MY_MOISTURE);
}