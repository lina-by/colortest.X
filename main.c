// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "card.h"
#include "lights.h"
#include "color.h"
#include "i2c.h"
#include "serial.h"
#include "interrupts.h"
#include "timers.h"
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

/**********************************
 *          COLOR CODES
 * white=0
 * red=1
 * blue=2
 * green=3
 * pink=4
 * yellow=5
 * orange=6
 * light blue=7
 * 
 * 
            //red = color_read_Red();
            //blue = color_read_Blue();
            //green = color_read_Green();
            //clear = color_read_Clear();
            //sprintf(&buf,"levels=%d ; red=%d ; blue=%d ; green=%d ; clear=%d\n", i,red,blue,green,clear);
            //TxBufferedString(&buf);
            //sendFLAG=1;
            //PIE4bits.TX4IE=1;
 **********************************/

void main(void){
    initUSART4();
    Interrupts_init();
    //INITIALIZATION
    color_click_init();
    LightInit();
    char i=0;
    unsigned char buf[100];
    while (1) {
        levels(i);
        sprintf(&buf,"levels=%d ; red=%d ; blue=%d ; green=%d ; clear=%d\n", i,red,blue,green,clear);
        TxBufferedString(&buf);
        sendFLAG=1;
        PIE4bits.TX4IE=1;
        //i=(i+1)%4;
    }
}
