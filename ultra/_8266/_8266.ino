//#include <Adafruit_ESP8266.h>

//#include <ESP8266wifi.h>

#define MEGA
#define SSID       "Itead_1(Public)"
#define PASSWORD   "27955416"


#include "uartWIFI.h"
#include <SoftwareSerial.h>
WIFI wifi;

extern int chlID;  //client id(0-4)


void setup()
{
  
  wifi.begin();
  bool b = wifi.Initialize(STA, SSID, PASSWORD);
  if(!b)
  {
    DebugSerial.println("Init error");
  }
  delay(8000);  //make sure the module can have enough time to get an IP address 
  String ipstring  = wifi.showIP();
  DebugSerial.println(ipstring);    //show the ip address of module
  
  delay(5000);
  wifi.confMux(1);
  delay(100);
  if(wifi.confServer(1,8080))
  DebugSerial.println("Server is set up");
  

}
void loop()
{
  
  char buf[100];
  int iLen = wifi.ReceiveMessage(buf);
  if(iLen > 0)
  {
    //if receive a "HELLO", send a "HELLO BACK" back to the client
    if (strcmp(buf, "HELLO") == 0)
    {
      DebugSerial.print("Get a message from id ");
      DebugSerial.print(chlID);
      DebugSerial.println(":");
      DebugSerial.println(buf); 
      
      DebugSerial.print("Send a message back to id ");
      DebugSerial.print(chlID);
      DebugSerial.println(":");
      DebugSerial.println("HELLO BACK");      
      wifi.Send(chlID,"HELLO BACK");
    }

  }
}
