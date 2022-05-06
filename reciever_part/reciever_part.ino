#include <VirtualWire.h>
const int ledPin = 9;
const int datain = 12;
void setup()
{
    Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_set_rx_pin(datain);
    vw_setup(2000);
    pinMode(ledPin, OUTPUT);
    vw_rx_start();
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      Serial.print("recieving");
      if(buf[0]=='1')
      {  
       digitalWrite(ledPin,HIGH);
      }  
      if(buf[0]=='0')
      {
       digitalWrite(ledPin,LOW);
      }
    }
}
