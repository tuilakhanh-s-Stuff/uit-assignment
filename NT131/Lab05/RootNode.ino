#include <Arduino.h>

#include "IPAddress.h"
#include "painlessMesh.h"

#include <ESPAsyncTCP.h>
#include <ESPAsyncWebSrv.h>

#define   MESH_SSID     "UwU"
#define   MESH_PASSWORD   "1234567809"
#define   MESH_PORT       5555

#define   STATION_SSID        "KhanhDZ"
#define   STATION_PASSWORD    "07092003"

const String ON("ON");
const String OFF("OFF");
const String UNKNOWN("UNKNOWN");
 
String ledState = UNKNOWN;
String nextLedState = UNKNOWN;
const int ledPin = D0;
 
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
painlessMesh  mesh;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script src="https://unpkg.com/htmx.org@1.9.10" integrity="sha384-D1Kt99CQMDuVetoL1lrYwg5t+9QdHe7NLX/SoJYkXDFfX37iInKRy5xLSi8nO7UC" crossorigin="anonymous"></script>
  <script src="https://unpkg.com/htmx.org/dist/ext/ws.js"></script>
</head>
<body>
  <div class="topnav">
    <h1>HE THONG NHUNG MANG KHONG DAY - LAB05</h1>
  </div>
  <div class="content" hx-ext="ws" ws-connect="/ws">
    <p>Websockets status: <span id="status"></span></p><br>
    <p>Root LED: <span id="root-led-state"></span></p>
    <button id="led-toggle-btn"
        hx-get="/toggle"
        hx-trigger="click"
        hx-target="#root-led-state"
        hx-swap="innerHTML"
      >
      TOGGLE
    </button>
    <div class="card" data-idx="0">
      <p>Node ID: <span class="node" data-type="id"></span></p>
      <p>Sensor temperature: <span class="sensor" data-type="temp"></span></p>
      <p>Sensor humidity: <span class="sensor" data-type="hum"></span></p>
      <div class="controls" data-type="leds"></div>
    </div>
    <div class="card" data-idx="1">
      <p>Node ID: <span class="node" data-type="id"></span></p>
      <p>Sensor luminous intensity: <span class="sensor" data-type="lux"></span></p>
      <div class="controls" data-type="leds"></div>
    </div>
  </div>

  <script type="text/javascript" defer>
    let status = document.getElementById("status");  
    
    let node0 = document.querySelector('[data-idx="0"]');
    let node1 = document.querySelector('[data-idx="1"]');
    
    let node0Id = node0.querySelector('[data-type="id"]');
    let node1Id = node1.querySelector('[data-type="id"]');

    let sensorTemp = node0.querySelector('[data-type="temp"]');
    let sensorHum = node0.querySelector('[data-type="hum"]');
    let sensorLux = node1.querySelector('[data-type="lux"]');

    let node0LedControls = node0.querySelector('[data-type="leds"]');
    let node1LedControls = node1.querySelector('[data-type="leds"]');

    let message;
    let content;
    let socket;
    let elt;

    const diffLedControls = (ledControls, content) => {
      let nodeId = content["node"];

      for (const led of content["data"]["leds"]) {
        let ledId = led["id"];
        let ledState = led["state"];

        let targetLedId = null;
        let targetLedState = null;
        let targetLedToggleBtn = null;

        let targetLedContainer = ledControls.querySelector(`[data-id="${ledId}"]`);
        if (targetLedContainer === null) {
          let _ledInfo = document.createElement("p");
          _ledInfo.innerHTML = `LED <span class="led-text" data-type="id"></span>: <span class="led-text" data-type="state"></span>`;

          let _ledToggleBtn = document.createElement("button");
          _ledToggleBtn.setAttribute("data-action", "toggle");
          _ledToggleBtn.classList.add("led-btn");
          _ledToggleBtn.innerText = "TOGGLE";

          let _ledContainer = document.createElement("div");
          _ledContainer.setAttribute("data-id", ledId);

          _ledContainer.appendChild(_ledInfo);
          targetLedId = _ledInfo.querySelector('[data-type="id"]');
          targetLedState = _ledInfo.querySelector('[data-type="state"]');
          targetLedToggleBtn = _ledContainer.appendChild(_ledToggleBtn);
          targetLedContainer = ledControls.appendChild(_ledContainer);
        } else {
          targetLedId = targetLedContainer.querySelector('[data-type="id"]');
          targetLedState = targetLedContainer.querySelector('[data-type="state"]');
          targetLedToggleBtn = targetLedContainer.querySelector('[data-action="toggle"]');
        }

        if (targetLedId.innerText !== ledId) {
          targetLedId.innerText = ledId;
        }

        if (targetLedState.innerText !== ledState) {
          targetLedState.innerText = ledState;
        }

        targetLedToggleBtn.onclick = () => {
          fetch(`/ledToggle/${nodeId}/${ledId}`, {method: 'GET'});
        };
      }
    }

    document.addEventListener("visibilitychange", function(evt) {
      console.log('visibilitychange', document.visibilityState);
      if (socket) {
        socket.send(document.visibilityState, elt);
      }
    });

    document.body.addEventListener('htmx:wsOpen', function(evt) {
      console.log('connected');
      
      socket = evt.detail.socketWrapper;
      elt = evt.detail.elt;

      status.innerText = 'Connected';
      status.setAttribute('data-status', 'connected');
    });

    document.body.addEventListener('htmx:wsClose', function(evt) {
      console.log('disconnected');
      status.innerText = 'Disconnected';
      status.setAttribute('data-status', 'disconnected');
    });

    document.body.addEventListener('htmx:wsBeforeMessage', function(evt) {
      message = evt.detail.message;
      socket = evt.detail.socketWrapper;
      elt = evt.detail.elt;

      console.log(`receive: ${message}`);

      if (message.startsWith("MSG")) {
        content = JSON.parse(message.replace("MSG:", ""));
        if (content.hasOwnProperty("data")) {
          let hasLuxData = content["data"].hasOwnProperty("lux");
          let hasTempData = content["data"].hasOwnProperty("temp");
          let hasHumData = content["data"].hasOwnProperty("hum");
          if (hasLuxData) {
            sensorLux.innerText = content["data"]["lux"];
            node1Id.innerText = content["node"];
            diffLedControls(node1LedControls, content);
          }
          if (hasTempData) {
            sensorTemp.innerText = content["data"]["temp"];
          }
          if (hasHumData) {
            sensorHum.innerText = content["data"]["hum"];
          }
          if (hasTempData && hasHumData) {
            node0Id.innerText = content["node"];
            node0Id.innerText = content["node"];
            diffLedControls(node0LedControls, content);
          }
        }
      }
    });
  </script>
</body>
</html>
)rawliteral";

// User stub
// Prototype
void receivedCallback( const uint32_t &from, const String &msg );
void sendMessage(); // Prototype so PlatformIO doesn't complain
void ledControl(AsyncWebServerRequest *request);
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len);
void newConnectionCallback(uint32_t nodeId);
IPAddress getlocalIP();

// who am i?
IPAddress myIP(0, 0, 0, 0);

void initIO() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void initMesh() {
  mesh.setDebugMsgTypes( ERROR | STARTUP | CONNECTION );  // set before init() so that you can see startup messages

  mesh.init( MESH_SSID, MESH_PASSWORD, MESH_PORT, WIFI_AP_STA, 6 );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);

  mesh.stationManual(STATION_SSID, STATION_PASSWORD);

  mesh.setRoot(true);
  mesh.setContainsRoot(true);

  Serial.println("My AP IP is " + IPAddress(mesh.getAPIP()).toString());
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void initServer() {
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/toggle", HTTP_GET, ledControl);

  server.on("/ledToggle/3038481794/0", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String nodeId("3038481794");
    String ledIdx(0);

    StaticJsonDocument<2048> msgJson;
    msgJson["action"] = "ledToggle";
    msgJson["node"] = nodeId;
    msgJson["id"] = ledIdx;
    
    String msg;
    serializeJson(msgJson, msg);
    Serial.printf("msg=%s, node=%s, ledIdx=%d\n", msg.c_str(), nodeId.c_str(), ledIdx.toInt());

    if (!mesh.sendBroadcast(msg)) {
      request->send(400, "text/plain", "Error");
    }

    request->send(200, "text/plain", "Ok");
  });

  server.on("/ledToggle/3038481794/1", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String nodeId("3038481794");
    String ledIdx(1);

    StaticJsonDocument<2048> msgJson;
    msgJson["action"] = "ledToggle";
    msgJson["node"] = nodeId;
    msgJson["id"] = ledIdx.toInt();
    
    String msg;
    serializeJson(msgJson, msg);
    Serial.printf("msg=%s, node=%s, ledIdx=%d\n", msg.c_str(), nodeId.c_str(), ledIdx.toInt());

    if (!mesh.sendBroadcast(msg)) {
      request->send(400, "text/plain", "Error");
    }

    request->send(200, "text/plain", "Ok");
  });

  server.on("/ledToggle/3038482123/0", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String nodeId("3038482123");
    String ledIdx(0);

    StaticJsonDocument<2048> msgJson;
    msgJson["action"] = "ledToggle";
    msgJson["node"] = nodeId;
    msgJson["id"] = ledIdx;
    
    String msg;
    serializeJson(msgJson, msg);
    Serial.printf("msg=%s, node=%s, ledIdx=%d\n", msg.c_str(), nodeId.c_str(), ledIdx.toInt());

    if (!mesh.sendBroadcast(msg)) {
      request->send(400, "text/plain", "Error");
    }

    request->send(200, "text/plain", "Ok");
  });
 
  // Start server
  server.begin();
}

void setup() {
  initIO();
  initMesh();
  initWebSocket();
  initServer();
}

void loop() {
  mesh.update();
  if (myIP != getlocalIP()) {
    myIP = getlocalIP();
    Serial.println("My IP is " + myIP.toString());
  }
  ws.cleanupClients();
}

// Needed for painless library
void receivedCallback( const uint32_t &from, const String &msg ) {
  Serial.printf("receive: from %u msg=%s\n", from, msg.c_str());
  ws.textAll(String("MSG:" + msg)); 
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("--> newConn: nodeId = %u\n", nodeId);
}

void ledControl(AsyncWebServerRequest *request) {
  if (nextLedState.compareTo(UNKNOWN) == 0) {
    nextLedState = ON;
  }

  if (nextLedState.compareTo(ON) == 0) {
    digitalWrite(ledPin, HIGH);
    ledState = nextLedState;
    nextLedState = OFF;
    Serial.println("Light is up");
  } else {
    digitalWrite(ledPin, LOW);
    ledState = nextLedState;
    nextLedState = ON;
    Serial.println("Light is down");
  }

  ws.textAll(String("LED:" + ledState));
  request->send(200, "text/plain", ledState);
}

void notifyClients() {
  ws.textAll(ledState);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle1") == 0) {
      ledState = !ledState;
      notifyClients();
    }
  }
}
 
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
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

IPAddress getlocalIP() {
  return IPAddress(mesh.getStationIP());
}