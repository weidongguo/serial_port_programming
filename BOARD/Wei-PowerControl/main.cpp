#include "mbed.h"
#include "PowerControl.h"
#include "EthernetPowerControl.h"
#include "RTC.h"
DigitalOut leds[] = {DigitalOut(LED1), DigitalOut(LED2), DigitalOut(LED3), DigitalOut(LED4)}; // put each LED object into an array, easier to access
Serial pc(USBTX, USBRX);

void ISR(void){
    leds[2] = !leds[2];
    leds[1] = !leds[1];
 }
 
 
int main() {
    
    //turn off other unused peripherals
    Peripheral_PowerDown( ~(LPC1768_PCONP_PCUART0 | LPC1768_PCONP_PCGPIO) );
   //turn off everything except for GPIO for LED and UART0 for serial port communication.

    set_time(1456096500); // Sun, 21 Feb 2016 23:15:00 GMT
    tm t = RTC::getDefaultTM();
    t.tm_sec = 5;
    RTC::alarm(&ISR, t); //send interrupt to wake up from sleep() mode .
                        // the RTC sends one interrupt every minute after the first 5 seconds
    leds[0] = 1;  
    char ch;
    while (true) {
       if(pc.readable()){
        ch = pc.getc();
        pc.putc(ch); 
       }
       
       leds[3] = !leds[3];
       sleep(); 
    }
}

