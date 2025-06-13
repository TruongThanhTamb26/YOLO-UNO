
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  initWiFi();
  initMQTT();
  initWebserver();
  // initDHT20();
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