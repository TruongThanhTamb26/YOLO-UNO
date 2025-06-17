#include "DHT20.h"

int Humidity = 0;    // Global variable to store humidity
int Temperature = 0; // Global variable to store temperature

DHT20 dht20; // Declare the DHT20 object

void TaskDHT20(void *pvParameters)
{
    while (true)
    {
        int result = dht20.read();
        if (result == DHT20_OK)
        {
            Humidity = dht20.getHumidity();
            Temperature = dht20.getTemperature();
            // Serial
            Serial.println(String(dht20.getTemperature()) + "-" + String(dht20.getHumidity()));
            // MQTT
            publishData("Temperature", String(dht20.getTemperature()));
            publishData("Humidity", String(dht20.getHumidity()));
        }
        else
        {
            Serial.println(result);
            Serial.println("Failed to read DHT20 sensor.");
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void initDHT20()
{
    dht20.begin();
    xTaskCreate(
        TaskDHT20,   // Function to implement the task
        "TaskDHT20", // Name of the task
        4096,        // Stack size in words
        NULL,        // Task input parameter
        2,           // Priority of the task
        NULL         // Task handle
    );
}