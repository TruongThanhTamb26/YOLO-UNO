
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  Wire.begin(MY_SDA, MY_SCL);

  initWiFi();
  initMQTT();
  initWebserver();

  initDHT20();
  initMoisture();
  initLightSensor();
  initHCSR04();

  initLCD();

  initRGB();
}

void loop()
{
  if (!Wifi_reconnect())
  {
    return;
  }
  reconnectMQTT();
  handleWebserver();
}