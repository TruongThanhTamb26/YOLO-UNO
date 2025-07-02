
#include "MQTT.h"

#define MQTT_SERVER "io.adafruit.com"
#define MQTT_PORT 1883

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length)
{
    String message;
    for (unsigned int i = 0; i < length; i++)
    {
        message += (char)payload[i];
    }
    if (strcmp(topic, (String(config.mqtt_user) + "/feeds/Temperature").c_str()) == 0)
    {
        Serial.println(message);
    }
    else if (strcmp(topic, (String(config.mqtt_user) + "/feeds/Humidity").c_str()) == 0)
    {
        Serial.println(message);
    }
}

void publishData(String feed, String data)
{
    String topic = String(config.mqtt_user) + "/feeds/" + feed;
    if (client.connected())
    {
        client.publish(topic.c_str(), data.c_str());
    }
}

void InitMQTT()
{
    Serial.println("Connecting to MQTT...");
    String clientId = "ESP32Client" + String(random(0, 1000));
    if (client.connect(clientId.c_str(), config.mqtt_user.c_str(), config.mqtt_user.c_str()))
    {
        Serial.println("MQTT Connected");
        String data = "hello";
        publishData("IP", WiFi.localIP().toString());
        Serial.println("Start");
    }
    else
    {
        Serial.print("MQTT connection failed, rc=");
        Serial.println(client.state());
        delay(1000);
    }
}

void reconnectMQTT()
{
    if (client.connected())
    {
        client.loop();
    }
    else
    {
        InitMQTT();
    }
}

void initMQTT()
{
    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);
}