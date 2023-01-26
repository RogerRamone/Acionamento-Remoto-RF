#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
boolean estado_b1 = 0;
boolean estado_b2 = 0;

void setup() {
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  pinMode(2,OUTPUT);
  pinMode(A5,OUTPUT);

}

void loop() {
  if(radio.available()){
    delay(10);
    radio.read(&estado_b1, sizeof(estado_b1));
    digitalWrite(2,estado_b1);
    delay(10);
    radio.read(&estado_b2, sizeof(estado_b2));
    digitalWrite(A5,estado_b2);
    delay(10);
  }
}
