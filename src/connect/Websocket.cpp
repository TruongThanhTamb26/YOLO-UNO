#include "Websocket.h"

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create a WebSocket object
AsyncWebSocket ws("/ws");

// Json Variable to Hold Sensor Readings
JSONVar readings;

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 3000;

// Get Sensor Readings and return JSON object
String getSensorReadings()
{
  readings["temperature"] = String(Temperature);
  readings["humidity"] = String(Humidity);
  readings["moisture"] = String(moisture_value);
  readings["distance"] = String(distanceValue);
  readings["light"] = String(lightValue);
  String jsonString = JSON.stringify(readings);
  return jsonString;
}

// Initialize LittleFS
void initLittleFS()
{
  if (!LittleFS.begin(true))
  {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  Serial.println("LittleFS mounted successfully");
}

void notifyClients(String sensorReadings)
{
  ws.textAll(sensorReadings); // Send sensor readings to all connected WebSocket clients
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {
    String msg = String((char *)data);

    if (msg == "getReadings")
    {
      String sensorReadings = getSensorReadings();
      notifyClients(sensorReadings);
    }
    else if (msg == "toggleLED")
    {
      ledMode = !ledMode; // Toggle LED mode
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type)
  {
  case WS_EVT_CONNECT:
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    handleWebSocketMessage(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void webSocket()
{
  if ((millis() - lastTime) > timerDelay)
  {
    String sensorReadings = getSensorReadings();
    Serial.print(sensorReadings);
    notifyClients(sensorReadings);

    lastTime = millis();
  }
  ws.cleanupClients();
  ElegantOTA.loop();
}

void initWebSocket()
{
  ws.onEvent(onEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });
  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/script.js", "application/javascript"); });
  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/styles.css", "text/css"); });

  server.begin();

  // Start server
  server.begin();

  // Start ElegantOTA
  ElegantOTA.begin(&server);
}
