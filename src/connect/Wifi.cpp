#include "Wifi.h"

void initWiFi()
{
    Serial.println("Connecting to AP ...");
    WiFi.begin(config.wifi_ssid, config.wifi_password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to AP");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

bool Wifi_reconnect()
{
    const wl_status_t status = WiFi.status();
    if (status == WL_CONNECTED)
    {
        return true;
    }
    initWiFi();
    return true;
}