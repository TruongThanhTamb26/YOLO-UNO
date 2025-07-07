
#include "globals.h"

void setup()
{
  Serial.begin(115200);
  Wire.begin(MY_SDA, MY_SCL);

  initLittleFS();    // Save the default configuration
  initAccessPoint(); // Initialize Access Point
  initConnect();

  // initDHT20();
  // initMoisture();
  // initLightSensor();
  // initHCSR04();

  // initLCD();
  // initRGB();
  // initRelayFan();
  initNeopixel();
  initLED();
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