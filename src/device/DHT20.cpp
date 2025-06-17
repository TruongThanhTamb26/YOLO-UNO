#include "DHT20.h"

DHT20 dht20; // Declare the DHT20 object

void TaskDHT20(void *pvParameters)
{
    while (true)
    {
        int result = dht20.read();
        if (result == DHT20_OK)
        {
            // LCD
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(dht20.getTemperature());
            lcd.print(" C");
            lcd.setCursor(0, 1);
            lcd.print("Hum: ");
            lcd.print(dht20.getHumidity());
            lcd.print(" %");
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
}