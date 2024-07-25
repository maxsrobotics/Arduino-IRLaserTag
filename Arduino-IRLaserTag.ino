#include <IRremote.h>
#include "util/crc16.h"

const int irSend = 9;
const int irRecv = 8;

void setup() {
  Serial.begin(9600);
  IrSender.begin(irSend);
  IrReceiver.begin(irRecv);
}

void loop() {
  IrSender.sendNECRaw(generatePacket(0xAA));

  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume(); // Prepare to receive the next value
  }
  delay(1000);
}

uint16_t generatePacket(uint8_t playerId) {
  uint8_t crc;
  crc = _crc8_ccitt_update(crc, playerId);
  uint16_t packet = (playerId << 8) | crc;
  return packet;
}