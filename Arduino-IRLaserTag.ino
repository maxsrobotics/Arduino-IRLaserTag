// Arduino IR Laser Tag Protocol - Custom Protocol

#include <IRremote.h>

const int irSend = 9;
const int irRecv = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  IrSender.begin(irSend);
  IrReceiver.begin(irRecv);
}

void loop() {
  // put your main code here, to run repeatedly:
  IrSender.sendNECRaw(0xAA, 0);

  if(IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  }
  delay(1000);
}
