#include "connect.h"

void initConnect()
{
  // Initialize WiFi
  initWiFi();

  // Initialize MQTT
  initMQTT();

  // Initialize Websocket
  initWebSocket();
}