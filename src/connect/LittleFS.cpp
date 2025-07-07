#include "LittleFS.h"

Config config;
bool info = false;

bool loadConfig()
{
  if (!LittleFS.begin())
  {
    Serial.println("LittleFS Mount Failed");
    return false;
  }

  File file = LittleFS.open("/config.json", "r");
  if (!file)
  {
    Serial.println("Failed to open config file");
    return false;
  }

  String content = file.readString(); // đọc toàn bộ file thành chuỗi
  file.close();

  JSONVar json = JSON.parse(content);
  if (JSON.typeof(json) != "object")
  {
    Serial.println("Failed to parse JSON");
    return false;
  }

  config.wifi_ssid = (const char *)json["wifi_ssid"];
  config.wifi_password = (const char *)json["wifi_password"];
  config.mqtt_user = (const char *)json["mqtt_user"];
  config.mqtt_key = (const char *)json["mqtt_key"];

  if (config.wifi_ssid == "" || config.mqtt_user == "" || config.mqtt_key == "")
  {
    Serial.println("Configuration is incomplete, please check your config.json file");
    info = false;
  }
  else
  {
    info = true;
  }

  Serial.println("Configuration loaded successfully:");
  Serial.println("WiFi SSID: " + config.wifi_ssid);
  Serial.println("WiFi Password: " + config.wifi_password);
  Serial.println("MQTT User: " + config.mqtt_user);
  Serial.println("MQTT Key: " + config.mqtt_key);

  return true;
}

bool saveConfig()
{
  JSONVar json;

  json["wifi_ssid"] = config.wifi_ssid;
  json["wifi_password"] = config.wifi_password;
  json["mqtt_user"] = config.mqtt_user;
  json["mqtt_key"] = config.mqtt_key;

  File file = LittleFS.open("/config.json", "w");
  if (!file)
  {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  file.print(JSON.stringify(json));
  file.close();
  Serial.println("Saving configuration:");
  Serial.println("WiFi SSID: " + config.wifi_ssid);
  Serial.println("WiFi Password: " + config.wifi_password);
  Serial.println("MQTT User: " + config.mqtt_user);
  Serial.println("MQTT Key: " + config.mqtt_key);
  return true;
}

// Initialize LittleFS
void initLittleFS()
{
  if (!LittleFS.begin(true))
  {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  Serial.println("LittleFS mounted successfully");
  loadConfig();
}
