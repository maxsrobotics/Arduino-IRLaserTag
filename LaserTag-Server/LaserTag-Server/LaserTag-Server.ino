#include <IRremote.h>

const int irSend = 9;
const int irRecv = 8;
const int buttonPin = 7;

bool lock = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  IrSender.begin(irSend);
  IrReceiver.begin(irRecv);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(buttonPin) && !lock) {
    Serial.println("Negotiation Beginning!");
    while (!IrReceiver.decode())
      ;
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  }
  lock = true;
}
