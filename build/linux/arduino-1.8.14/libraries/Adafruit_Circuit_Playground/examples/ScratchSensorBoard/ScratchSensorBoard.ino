// example sketch to turn your circuit playground into a picoboard
// potentiometer is 'simulated' by tilting the cplay (accelerometer Z is reported)
// pin #13 red LED is lit when data is sent to Scratch!

#include <Adafruit_CircuitPlayground.h>

#define SCRATCH_DATA_REQUEST  0x01
#define SCRATCH_FW_VER        0x04

void setup() {
  while (!Serial);
  Serial.begin(38400);
  //Serial.println("Start!");

  CircuitPlayground.begin();
  pinMode(13, OUTPUT);
}

void loop() {
  if (!Serial.available())
    return;

  char c = Serial.read();

  if (c != SCRATCH_DATA_REQUEST)
    return;

  digitalWrite(13, HIGH);
  // data is a request!
  sendPacket(0xF, SCRATCH_FW_VER);
  sendPacket(0x0, analogRead(A0));
  sendPacket(0x1, analogRead(A1));
  sendPacket(0x2, analogRead(A2));
  if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) {
    sendPacket(0x3, 0x0);
  } else {
    sendPacket(0x3, 0xFFFF);
  }
  sendPacket(0x4, CircuitPlayground.temperature() * 10);
  sendPacket(0x5, 1023 - CircuitPlayground.lightSensor());
  float s = CircuitPlayground.mic.soundPressureLevel(10);
  sendPacket(0x6, s);
  float z = CircuitPlayground.motionZ();
  z *= -50; // reverse direction
  z += 512;
  sendPacket(0x7, z);

  digitalWrite(13, LOW);
}

void sendPacket(uint8_t channel, uint16_t data) {
  uint8_t packet0, packet1;

  channel &= 0xF;
  if (data >= 1024) data = 1023;
  
  packet0 = 0x80 | (channel << 3) | ((data >> 7) & 0x7);
  packet1 = data & 0x7F;

  Serial.write(packet0);
  //delay(1);
  Serial.write(packet1);
  //delay(1);
}
