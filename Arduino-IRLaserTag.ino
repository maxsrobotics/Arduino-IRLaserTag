#include <IRremote.h>

const int irSend = 9;
const int irRecv = 8;

const uint16_t shotArray[] = {
  0xAA, 0x24
};

void setup() {
  Serial.begin(9600);
  IrSender.begin(irSend);
  IrReceiver.begin(irRecv);
}

void loop() {
  for(int i = 0; i < sizeof(shotArray) / sizeof(uint16_t); i++) {
    IrSender.sendNECRaw(shotArray[i]);
    delay(50);
  }

  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume(); // Prepare to receive the next value
  }
  delay(1000);
}
