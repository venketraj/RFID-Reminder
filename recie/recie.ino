#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#define buzzerpin 6
#define led 9
RH_ASK driver;

void setup()
{
  pinMode(buzzerpin, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
}

void loop()
{

  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    delay(600);
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
  }
  else
  {
    delay(500);
    Serial.println("not in range");
    digitalWrite(buzzerpin, HIGH);
    delay(500);
    digitalWrite(buzzerpin, LOW);
    
    
    
  }

}
