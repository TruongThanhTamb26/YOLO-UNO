#include "Webserver.h"

// LED D13
const int LED = 48;
String LEDState = "off";

String colorState[10] = {"off", "off", "off", "off", "off", "off", "off", "off", "off", "off"};
WebServer server(80);

void handleRoot()
{
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <meta name="viewport" content="width=device-width, initial-scale=1">
            <script>
      function fetchSensorData() {
        fetch("/sensor")
          .then(response => response.json())
          .then(data => {
            document.getElementById("temperature").textContent = data.temperature;
            document.getElementById("humidity").textContent = data.humidity;
            document.getElementById("distance").textContent = data.distance;
            document.getElementById("moisture").textContent = data.moisture;
            document.getElementById("light").textContent = data.light;
          });
      }

      setInterval(fetchSensorData, 2000); // Update every 2 seconds
      </script>
      <style>
        body {
          font-family: Arial, sans-serif;
          text-align: center;
          margin: 0;
          padding: 20px;
          background-color: #f4f4f4;
        }
        h1 {
          color: #333;
        }
        .section {
          margin-bottom: 40px;
        }
        .btn {
          padding: 10px 16px;
          font-size: 14px;
          border: none;
          border-radius: 6px;
          margin: 5px;
          cursor: pointer;
          transition: background 0.3s;
          min-width: 100px;
        }
        .on {
          background-color: #4CAF50;
          color: white;
        }
        .on:hover {
          background-color: #45a049;
        }
        .off {
          background-color: #888888;
          color: white;
        }
        .off:hover {
          background-color: #666666;
        }
        .scroll-container {
          display: flex;
          overflow-x: auto;
          padding: 10px 0;
          justify-content: center;
        }
      </style>
    </head>
    <body>
      <h1>ESP32 Web Server</h1>

      <div class='section'>
        <h2>LED Control</h2>
        <a href="/LED/LED_STATE_LINK">
          <button class="btn LED_STATE_CLASS">LED LED_STATE_TEXT</button>
        </a>
      </div>

      <div class='section'>
        <h2>RGB Color Control</h2>
        <div class='scroll-container'>
  )rawliteral";

  // LED ON/OFF nút
  String ledLink = LEDState == "off" ? "on" : "off";
  String ledClass = LEDState == "off" ? "on" : "off";
  String ledText = LEDState == "off" ? "ON" : "OFF";
  html.replace("LED_STATE_LINK", ledLink);
  html.replace("LED_STATE_CLASS", ledClass);
  html.replace("LED_STATE_TEXT", ledText);

  // RGB button list
  const char *colors[9] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Purple", "White", "Black"};
  const char *paths[9] = {"red", "orange", "yellow", "green", "blue", "indigo", "purple", "white", "black"};

  for (int i = 0; i < 9; i++)
  {
    String btnClass = colorState[i] == "off" ? "on" : "off";
    String btnText = String(colors[i]) + (colorState[i] == "off" ? " ON" : " OFF");
    String path = "/RGB/" + String(paths[i]) + "/" + (colorState[i] == "off" ? "on" : "off");

    html += "<a href=\"" + path + "\"><button class=\"btn " + btnClass + "\">" + btnText + "</button></a>";
  }
  html += R"rawliteral(
        </div>
      </div>

      <div class='section'>
        <h2>Sensor Data</h2>
  )rawliteral";
  // Display sensor data
  html += "<p>Temperature: <span id=\"temperature\">" + String(Temperature) + "</span> C</p>";
  html += "<p>Humidity: <span id=\"humidity\">" + String(Humidity) + "</span> %</p>";
  html += "<p>Distance: <span id=\"distance\">" + String(distanceValue) + "</span> cm</p>";
  html += "<p>Moisture: <span id=\"moisture\">" + String(moisture_value) + "</span> %</p>";
  html += "<p>Light: <span id=\"light\">" + String(lightValue) + "</span> %</p>";
  html += R"rawliteral(
      </div>
    </body>
    </html>
  )rawliteral";
  // Send the HTML response

  server.send(200, "text/html", html);
}

// Function to handle turning GPIO 26 on
void handleLEDOn()
{
  LEDState = "on";
  digitalWrite(LED, HIGH);
  handleRoot();
}

// Function to handle turning GPIO 26 off
void handleLEDOff()
{
  LEDState = "off";
  digitalWrite(LED, LOW);
  handleRoot();
}

// default color state for RGB
void defaultColorState()
{
  for (int i = 0; i < 10; i++)
  {
    colorState[i] = "off";
  }
}

void handleRGBredON()
{
  currentColor = COLOR_RED;
  Auto = false;
  defaultColorState();
  colorState[0] = "on";
  handleRoot();
}

void handleRGBredOFF()
{
  Auto = true;
  colorState[0] = "off";
  handleRoot();
}

void handleRGBorangeON()
{
  currentColor = COLOR_ORANGE;
  Auto = false;
  defaultColorState();
  colorState[1] = "on";
  handleRoot();
}

void handleRGBorangeOFF()
{
  Auto = true;
  colorState[1] = "off";
  handleRoot();
}

void handleRGByellowON()
{
  currentColor = COLOR_YELLOW;
  Auto = false;
  defaultColorState();
  colorState[2] = "on";
  handleRoot();
}

void handleRGByellowOFF()
{
  Auto = true;
  colorState[2] = "off";
  handleRoot();
}

void handleRGBgreenON()
{
  currentColor = COLOR_GREEN;
  Auto = false;
  defaultColorState();
  colorState[3] = "on";
  handleRoot();
}

void handleRGBgreenOFF()
{
  Auto = true;
  colorState[3] = "off";
  handleRoot();
}

void handleRGBblueON()
{
  currentColor = COLOR_BLUE;
  Auto = false;
  defaultColorState();
  colorState[4] = "on";
  handleRoot();
}

void handleRGBblueOFF()
{
  Auto = true;
  colorState[4] = "off";
  handleRoot();
}

void handleRGBindigoON()
{
  currentColor = COLOR_INDIGO;
  Auto = false;
  defaultColorState();
  colorState[5] = "on";
  handleRoot();
}

void handleRGBindigoOFF()
{
  Auto = true;
  colorState[5] = "off";
  handleRoot();
}

void handleRGBpurpleON()
{
  currentColor = COLOR_PURPLE;
  Auto = false;
  defaultColorState();
  colorState[6] = "on";
  handleRoot();
}

void handleRGBpurpleOFF()
{
  Auto = true;
  colorState[6] = "off";
  handleRoot();
}

void handleRGBwhiteON()
{
  currentColor = COLOR_WHITE;
  Auto = false;
  defaultColorState();
  colorState[7] = "on";
  handleRoot();
}

void handleRGBwhiteOFF()
{
  Auto = true;
  colorState[7] = "off";
  handleRoot();
}

void handleRGBblackON()
{
  currentColor = COLOR_BLACK;
  Auto = false;
  defaultColorState();
  colorState[8] = "on";
  handleRoot();
}

void handleRGBblackOFF()
{
  Auto = true;
  colorState[8] = "off";
  handleRoot();
}

void initWebserver()
{
  Serial.begin(115200);

  // Initialize the output variables as outputs
  pinMode(LED, OUTPUT);
  // Set outputs to LOW
  digitalWrite(LED, LOW);

  // Set up the web server to handle different routes
  server.on("/", handleRoot);
  server.on("/LED/on", handleLEDOn);
  server.on("/LED/off", handleLEDOff);
  server.on("/RGB/red/on", handleRGBredON);
  server.on("/RGB/red/off", handleRGBredOFF);
  server.on("/RGB/orange/on", handleRGBorangeON);
  server.on("/RGB/orange/off", handleRGBorangeOFF);
  server.on("/RGB/yellow/on", handleRGByellowON);
  server.on("/RGB/yellow/off", handleRGByellowOFF);
  server.on("/RGB/green/on", handleRGBgreenON);
  server.on("/RGB/green/off", handleRGBgreenOFF);
  server.on("/RGB/blue/on", handleRGBblueON);
  server.on("/RGB/blue/off", handleRGBblueOFF);
  server.on("/RGB/indigo/on", handleRGBindigoON);
  server.on("/RGB/indigo/off", handleRGBindigoOFF);
  server.on("/RGB/purple/on", handleRGBpurpleON);
  server.on("/RGB/purple/off", handleRGBpurpleOFF);
  server.on("/RGB/white/on", handleRGBwhiteON);
  server.on("/RGB/white/off", handleRGBwhiteOFF);
  server.on("/RGB/black/on", handleRGBblackON);
  server.on("/RGB/black/off", handleRGBblackOFF);

  // Handle sensor data request
  server.on("/sensor", []()
            {
  String json = "{";
  json += "\"temperature\":" + String(Temperature) + ",";
  json += "\"humidity\":" + String(Humidity) + ",";
  json += "\"distance\":" + String(distanceValue) + ",";
  json += "\"moisture\":" + String(moisture_value) + ",";
  json += "\"light\":" + String(lightValue);
  json += "}";
  server.send(200, "application/json", json); });

  // Start the web server
  server.begin();
  Serial.println("HTTP server started");
}

void handleWebserver()
{
  // Handle client requests
  server.handleClient();
}
