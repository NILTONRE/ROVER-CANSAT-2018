#include<LORA.h>
#include <SPI.h>
#include <SoftwareSerial.h>
LORA lora;

unsigned char flag=1; 
unsigned char rx_len;
unsigned char rx_buf[20];

void setup() {
  Serial.begin(9600);
  if(!lora.init())
  {
     Serial.println("Init fail!");
  }
   lora.rxInit();   
}
void loop() 
{
    if(flag==1)
    {
        if(lora.waitIrq(LR_RXDONE_MASK))    // espere la interrupción de RXDONE
        {
            lora.clrInterrupt();
            rx_len=lora.rxPacket(rx_buf);// LEE rx 
            Serial.write(rx_buf,rx_len);    //
            Serial.println();
            lora.rxInit();    // 
        }
    }
}
