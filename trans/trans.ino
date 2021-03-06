#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#define led 9
RH_ASK driver;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
}

void loop()
{
  delay(25);
  const char *msg = "Hello World!";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println("transmitting");
  digitalWrite(led,HIGH);
  delay(50);
  digitalWrite(led,LOW);
}
