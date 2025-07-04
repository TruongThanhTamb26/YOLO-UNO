#ifndef GLOBALS_H
#define GLOBALS_H

// include libraries
#include <Wire.h>
#include <WiFi.h>
// #include <WebServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include "LittleFS.h"
#include <Arduino_JSON.h>
#include <DHT20.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <LCD_I2C.h>
#include <gravity_soil_moisture_sensor.h>
#include <Adafruit_NeoPixel.h>

// CONNECTIVITY
#include "../src/connect/Wifi.h"
#include "../src/connect/MQTT.h"
#include "../src/connect/Websocket.h"
#include "../src/connect/LittleFS.h"
#include "../src/connect/connect.h"

// INPUT
#include "../src/device/DHT20.h"
#include "../src/device/HCSR04.h"
#include "../src/device/Moisture.h"
#include "../src/device/Light_sensor.h"

// OUTPUT
#include "../src/device/LCD.h"
#include "../src/device/RGB.h"
#include "../src/device/Relay.h"
#include "../src/device/Fan.h"
#include "../src/device/Relay_Fan.h"
#include "../src/device/LED.h"
#include "../src/device/TrafficLight.h"

#define MY_SCL 12
#define MY_SDA 11
#define MY_TRIG 18
#define MY_ECHO 21
#define MY_MOISTURE 1
#define MY_LIGHT 2
#define MY_RGB 6
#define MY_RELAY 8
#define MY_FAN 10
#define MY_LED 48
#define MY_TRAFFIC_LIGHT 7

struct Config
{
  String wifi_ssid;
  String wifi_password;
  String mqtt_user;
  String mqtt_key;
};

extern Config config; // Global configuration variable

#endif