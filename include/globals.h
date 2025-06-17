#ifndef GLOBALS_H
#define GLOBALS_H

// include libraries
#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DHT20.h>
#include <PubSubClient.h>
#include <HCSR04.h>
#include <LCD_I2C.h>

///
#include "../src/connect/Wifi.h"
#include "../src/connect/MQTT.h"
#include "../src/connect/Webserver.h"

#include "../src/device/DHT20.h"
#include "../src/device/HCSR04.h"
#include "../src/device/LCD.h"

#define delay_time 10000
#define MY_SCL 12
#define MY_SDA 11
#define MY_TRIG 10
#define MY_ECHO 17

#endif