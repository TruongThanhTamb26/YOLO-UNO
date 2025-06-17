#include "Light_sensor.h"

int lightValue = 0;

void TaskLightSensor(void *pvParameters)
{
  while (true)
  {
    int lightValue = analogRead(MY_LIGHT);
    int percentage = map(lightValue, 0, 4095, 0, 100);
    // LCD
    lcd.setCursor(0, 0);
    lcd.print("Light:");
    lcd.print(percentage);
    lcd.print(" %");
    // Serial
    Serial.println("Light Sensor Value: " + String(percentage) + "%");
    // MQTT
    publishData("Light", String(percentage));
    vTaskDelay(5000 / portTICK_PERIOD_MS); // Update every 5 seconds
  }
}

void initLightSensor()
{
  // Initialize the light sensor
  pinMode(MY_LIGHT, INPUT);
}