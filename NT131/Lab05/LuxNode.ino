#include "painlessMesh.h"
#include <Wire.h>
#include <BH1750.h>
#include <ArduinoJson.h>

#define   BAUD_RATE       115200
#define   MESH_PREFIX     "UwU"
#define   MESH_PASSWORD   "1234567809"
#define   MESH_PORT       5555

const String ON("ON");
const String OFF("OFF");
const String UNKNOWN("UNKNOWN");

String ledState[] = {UNKNOWN};
String nextLedState[] = {UNKNOWN};
const int ledPin[] = {D3};
int ledCount = sizeof(ledPin) / sizeof(*ledPin);

BH1750 lightMeter(0x23);
Scheduler userScheduler; // to control your personal task
painlessMesh  mesh;

StaticJsonDocument<2048> msgJson;

void sendMessage();

Task taskSendMessage( TASK_SECOND * 2 , TASK_FOREVER, &sendMessage );

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
  lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE, 0x23, &Wire);
  float lux = lightMeter.readLightLevel();

  StaticJsonDocument<2048> msgJson;

  JsonObject dataJson = msgJson.createNestedObject("data");
  msgJson["node"] = mesh.getNodeId();
  dataJson["lux"] = lux;

  JsonArray ledsArr = dataJson.createNestedArray("leds");
  for (int ledIdx = 0; ledIdx < ledCount; ledIdx++) {
    JsonObject ledJson = ledsArr.createNestedObject();
    ledJson["id"] = ledIdx;
    ledJson["state"] = ledState[ledIdx].c_str();
  }

  String msg;
  serializeJson(msgJson, msg);

  // Send message broadcast
  Serial.printf("sendMessage: Sent msg=%s\n", msg.c_str());
  mesh.sendBroadcast( msg );
  taskSendMessage.setInterval( TASK_SECOND * 2 );
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("receive: node=%u, msg=%s\n", from, msg.c_str());

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
  Serial.printf("--> conn: new node=%u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void initIO() {
  Serial.begin( BAUD_RATE );

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin(D2, D1);
  // On esp8266 you can select SCL and SDA pins using Wire.begin(D4, D3);
  // For Wemos / Lolin D1 Mini Pro and the Ambient Light shield use Wire.begin(D2, D1);

  for (int ledIdx = 0; ledIdx < ledCount; ledIdx++) {
    int _ledPin = ledPin[ledIdx];
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, LOW);
    ledState[ledIdx] = OFF;
    nextLedState[ledIdx] = ON;
  }
}

void initMesh() {
  // mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
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
  // it will run the user scheduler as well
  mesh.update();
}
