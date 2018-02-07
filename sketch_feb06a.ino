
#include <VirtualWire.h>
byte msg[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming message
byte len=VW_MAX_MESSAGE_LEN;
void setup()
{
Serial.begin(9600);
Serial.println("Device is ready");
// Initialize the IO and ISR
vw_setup(2000); // used for Bits per sec
vw_rx_start(); // Starting the receiver
}
void loop()
{
if (vw_get_message(msg, &len))
{
for(int i=0;i<len;++i)
Serial.print(char(msg[i]));
Serial.println();
}
}

