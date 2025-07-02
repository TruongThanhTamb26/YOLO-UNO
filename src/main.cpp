
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  Wire.begin(MY_SDA, MY_SCL);

  initLittleFS();
  initWiFi();
  initMQTT();
  initAccessPoint();
  initWebSocket();

  // initDHT20();
  // initMoisture();
  // initLightSensor();
  // initHCSR04();

  // initLCD();
  // initRGB();
  // initRelayFan();
  // initLED();
}

void loop()
{
  if (!Wifi_reconnect())
  {
    return;
  }
  reconnectMQTT();
  webSocket();
}