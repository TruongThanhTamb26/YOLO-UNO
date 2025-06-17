#ifndef GLOBALS_H
#define GLOBALS_H

// include libraries
#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DHT20.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <LCD_I2C.h>
#include <gravity_soil_moisture_sensor.h>
#include <Adafruit_NeoPixel.h>

// CONNECTIVITY
#include "../src/connect/Wifi.h"
#include "../src/connect/MQTT.h"
#include "../src/connect/Webserver.h"

// INPUT
#include "../src/device/DHT20.h"
#include "../src/device/HCSR04.h"
#include "../src/device/LCD.h"
#include "../src/device/Moisture.h"
#include "../src/device/Light_sensor.h"

// OUTPUT
#include "../src/device/RGB.h"

#define MY_SCL 12
#define MY_SDA 11
#define MY_TRIG 18
#define MY_ECHO 21
#define MY_MOISTURE 1
#define MY_LIGHT 2
#define MY_RGB 6

#endif