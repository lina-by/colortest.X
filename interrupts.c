#include <xc.h>
#include "interrupts.h"
#include "serial.h"
#include "timers.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
    INTCONbits.PEIE=1; // turn on peripheral interrupts
    INTCONbits.IPEN=1; // enable overflow interrupt
    PIE4bits.RC4IE=1;	//enable receive interrupt
    PIE4bits.TX4IE=0;	//transmit interrupt (only turn on when you have more than one byte to send)
    PIE0bits.TMR0IE=1; // enable interrupt source TMR0IF in PIE0 (for the overflow interrupt)
    INTCONbits.GIE=1;  //turn on interrupts globally (when this is off, all interrupts are deactivated)
    // turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
    //Send characters
	if(PIR4bits.TX4IF & sendFLAG){        //check the overflow interrupt source
        TX4REG = getCharFromTxBuf();//fill and therefore and clear the interrupt flag
        if (!isDataInTxBuf()){
            PIE4bits.TX4IE=0;
            sendFLAG=0;
        } //when there's no more data to send, disable the interrupt
        LATDbits.LATD7=!LATDbits.LATD7; //toggle an LED
	}
    //Read characters
    if(PIR4bits.RC4IF){        //check the interrupt source
        char reg = RC4REG;
        putCharToRxBuf(reg); //read and therefore and clear the interrupt flag
        charFLAG=1;
	}
}

