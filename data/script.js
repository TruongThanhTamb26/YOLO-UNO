var gateway = `ws://${window.location.hostname}/ws`;
var websocket;

window.addEventListener('load', onload);

function onload(event) {
  initWebSocket();

  // Nếu có form cấu hình thì mới thêm listener
  const configForm = document.getElementById("configForm");
  if (configForm) {
    configForm.addEventListener("submit", function (event) {
      event.preventDefault();

      const ssid = document.getElementById("wifissid").value;
      const password = document.getElementById("wifiPassword").value;
      const mqttUser = document.getElementById("mqttUser").value;
      const mqttKey = document.getElementById("mqttKey").value;

      const configData = {
        type: "config_update",
        wifi_ssid: ssid,
        wifi_password: password,
        mqtt_user: mqttUser,
        mqtt_key: mqttKey
      };

      websocket.send(JSON.stringify(configData));
      alert("Config sent to ESP32!");
    });
  }
}

function initWebSocket() {
  console.log('Trying to open WebSocket connection…');
  websocket = new WebSocket(gateway);
  websocket.onopen = onOpen;
  websocket.onclose = onClose;
  websocket.onmessage = onMessage;
}

function onOpen(event) {
  console.log('Connection opened');
  getReadings();
}

function onClose(event) {
  console.log('Connection closed');
  setTimeout(initWebSocket, 2000);
}

function getReadings() {
  if (websocket.readyState === WebSocket.OPEN) {
    websocket.send("getReadings");
  }
}

function onMessage(event) {
  try {
    console.log(event.data);
    var myObj = JSON.parse(event.data);
    var keys = Object.keys(myObj);

    for (var i = 0; i < keys.length; i++) {
      var key = keys[i];
      let el = document.getElementById(key);
      if (el) el.innerHTML = myObj[key];
    }
  } catch (e) {
    console.error("Invalid JSON received: ", e);
  }
}

function toggleLED() {
  websocket.send("toggleLED");
}
