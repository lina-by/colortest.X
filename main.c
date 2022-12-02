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
        if(color==0){unsigned char buf[]={'w','h', '\n'};}
        if(color==1){unsigned char buf[]={'r','e', '\n'};}
        if(color==2){unsigned char buf[]={'b','l', '\n'};}
        if(color==3){unsigned char buf[]={'g','r', '\n'};}
        if(color==4){unsigned char buf[]={'p','i', '\n'};}
        if(color==5){unsigned char buf[]={'y','e', '\n'};}
        if(color==6){unsigned char buf[]={'o','r', '\n'};}
        //if(color==7){unsigned char buf[]="light blue\n";}
 **********************************/

void main(void){   
    Timer0_init();
    initUSART4();
    Interrupts_init();
    //INITIALIZATION
    color_click_init();
    LightInit();
    char j;
    unsigned char buf;
    while (1) {
        unsigned char color = readcard();
        char a=color+1;
        if(color==0){unsigned char buf[]="white ";}
        if(color==1){unsigned char buf[]="red ";}
        if(color==2){unsigned char buf[]="blue ";}
        if(color==3){unsigned char buf[]="green ";}
        if(color==4){unsigned char buf[]="pink ";}
        if(color==5){unsigned char buf[]="yellow ";}
        if(color==6){unsigned char buf[]="orange ";}
        if(color==7){unsigned char buf[]="light blue ";}
        TxBufferedString(&buf);
        Light(0);
        sendFLAG=1;
        PIE4bits.TX4IE=1;
        for (j=0;j<3;j++){__delay_ms(900);}
    }     
}
