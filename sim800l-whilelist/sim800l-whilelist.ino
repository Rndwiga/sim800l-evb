/* Processing Received SMS through white list. 
If phone number is not on phonebook (contacts) rejects anything from them.
If so, turns ON LED on pin 13 on Arduino UNO board      */

#include <SoftwareSerial.h>
#include <gprs.h>

// Timeout SIMCard to respond
#define TIMEOUT    5000

//SIM800 TX is connected to Arduino D8
#define SIM800_TX_PIN 8
 
//SIM800 RX is connected to Arduino D7
#define SIM800_RX_PIN 7
 
//Create software serial object to communicate with SIM800
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);

// Create GPRS object to apply SIM commands with  SIM800
GPRS gprs;



void setup() {

  /*****************************************************************Begining--Initialization Module***********************************************************************/
  
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Starting SIM800 SMS Command Processor");
  gprs.preInit();
  delay(1000);
 
  while(0 != gprs.init()) {
      delay(1000);
      Serial.print("init error\r\n");
  } 
  Serial.print("Initialization Succesfull!\r\n");
  
 /*****************************************************************End--Initialization Module***********************************************************************/
  
}
  
void loop() {

}





