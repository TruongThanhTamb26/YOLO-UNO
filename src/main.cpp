
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  initMQTT();
  initDHT20();
  initHCSR04();
  initWebserver();
}

void loop()
{
  if (!Wifi_reconnect())
  {
    return;
  }
  reconnectMQTT();
}