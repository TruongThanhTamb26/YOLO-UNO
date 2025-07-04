#include "connect.h"

void initConnect()
{
  // Initialize Access Point
  initAccessPoint();

  // Initialize WiFi
  initWiFi();

  // Initialize MQTT
  initMQTT();

  // Initialize Websocket
  initWebSocket();
}