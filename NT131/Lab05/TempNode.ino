#include "painlessMesh.h"
#include <ArduinoJson.h> 
#include <DHT.h>

#define   MESH_PREFIX     "UwU"
#define   MESH_PASSWORD   "1234567809"
#define   MESH_PORT       5555

const String ON("ON");
const String OFF("OFF");
const String UNKNOWN("UNKNOWN");
 
String ledState[] = {UNKNOWN, UNKNOWN};
String nextLedState[] = {UNKNOWN, UNKNOWN};
const int ledPin[] = {D6, D7};
int ledCount = sizeof(ledPin) / sizeof(*ledPin);

const int DHTPIN = D1;
const int DHTTYPE = DHT22;
DHT dht(DHTPIN, DHTTYPE);


Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;

// User stub
void sendMessage() ; // Prototype so PlatformIO doesn't complain

Task taskSendMessage( TASK_SECOND * 1 , TASK_FOREVER, &sendMessage );

void ledControl(int ledIdx) {
  int _ledPin = ledPin[ledIdx];
  String _ledState = ledState[ledIdx];
  String _nextLedState = nextLedState[ledIdx];

  if (_nextLedState.compareTo(UNKNOWN) == 0) {
    _nextLedState = ON;
  }

  if (_nextLedState.compareTo(ON) == 0) {
    digitalWrite(_ledPin, HIGH);
    _ledState = _nextLedState;
    _nextLedState = OFF;
    Serial.printf("Light %d is up\n", _ledPin);
  } else {
    digitalWrite(_ledPin, LOW);
    _ledState = _nextLedState;
    _nextLedState = ON;
    Serial.printf("Light %d is down\n", _ledPin);
  }

  ledState[ledIdx] = _ledState;
  nextLedState[ledIdx] = _nextLedState;
}

void sendMessage() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  StaticJsonDocument<2048> msgJson;
  JsonObject dataJson = msgJson.createNestedObject("data");
  msgJson["node"] = mesh.getNodeId();
  dataJson["temp"] = temp;
  dataJson["hum"] = hum;

  JsonArray ledsArr = dataJson.createNestedArray("leds");
  for (int ledIdx = 0; ledIdx < ledCount; ledIdx++) {
    JsonObject ledJson = ledsArr.createNestedObject();
    ledJson["id"] = ledIdx;
    ledJson["state"] = ledState[ledIdx].c_str();
  }

  String msg;
  serializeJson(msgJson, msg);
  
  Serial.printf("%s\n", msg.c_str()); 
  mesh.sendBroadcast(msg);
  taskSendMessage.setInterval(TASK_SECOND * 3);
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("receive: node=%u, msg=%s\n", from, msg.c_str());

  StaticJsonDocument<2048> msgJson;
  deserializeJson(msgJson, msg);

  const String action(msgJson["action"]);
  const String nodeId(msgJson["node"]);

  if (action.compareTo(String("ledToggle")) != 0) {
    return;
  }
  
  if (nodeId.compareTo(String(mesh.getNodeId())) != 0) {
    Serial.printf("Not current node=%s\n", nodeId.c_str());
    return;
  }

  const int ledIdx = String(msgJson["id"]).toInt();
  if (ledIdx > ledCount || ledIdx < 0) {
    Serial.printf("Led out of bound ledCount=%d, ledIdx=%d\n", ledCount, ledIdx);
    return;
  }
  ledControl(ledIdx);
  Serial.printf("Toggled ledIdx %d\n", ledIdx);
}

void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void initIO() {
  Serial.begin(115200);
  dht.begin();
  for (int ledIdx = 0; ledIdx < ledCount; ledIdx++) {
    int _ledPin = ledPin[ledIdx];
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, LOW);
    ledState[ledIdx] = OFF;
    nextLedState[ledIdx] = ON;
  }
}

void initMesh() {
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, 6 );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
}

void setup() {
  initIO();
  initMesh();
}

void loop() {
  mesh.update();
}
