#ifndef GLOBALS_H
#define GLOBALS_H

// include libraries
#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DHT20.h>
#include <PubSubClient.h>
#include <HCSR04.h>

///
#include "../src/connect/TaskWifi.h"
#include "../src/connect/TaskMQTT.h"
#include "../src/connect/TaskWebserver.h"

#include "../src/device/TaskDHT20.h"
#include "../src/device/TaskHCSR04.h"

#define delay_time 10000
#define MY_SCL 11
#define MY_SDA 12
#define MY_TRIG 10
#define MY_ECHO 17

#endif