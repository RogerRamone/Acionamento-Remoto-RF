#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
boolean estado_b1 = 0;
boolean estado_b2 = 0;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

}

void loop() {
  
  radio.write(&estado_b1,sizeof(estado_b1));
  estado_b1 = digitalRead(2);
  delay(10);

  radio.write(&estado_b2,sizeof(estado_b2));
  estado_b2 = digitalRead(3);
  delay(10);
  
}
