#include <LORA.h>
#include <SPI.h>
#include <SoftwareSerial.h>
LORA lora;

void setup() {
  Serial.begin(9600);
  if(!lora.init())
  {
     Serial.println("Init fail!");
  }
}
void loop() 
{       unsigned char tx_buf[]={"ARLIIS2018"};// dato de prueva 
        unsigned char val;
       
        lora.txPacket(tx_buf, sizeof(tx_buf));
        lora.enterStbyMode();    // 
        Serial.println("enviado¡");
        delay(1000);
    
}





