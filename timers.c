#include <xc.h>
#include "timers.h"

/************************************
 * Function to set up timer 0
************************************/
void Timer0_init(void)
{
    T0CON1bits.T0CS=0b010; // Fosc/4 (Clock source setting bits)
    T0CON1bits.T0ASYNC=1; // see datasheet errata - needed to ensure correct operation when Fosc/4 used as clock source (Asynchronous to system clock - needed for correct operation when using Fosc as timer source)
    T0CON1bits.T0CKPS=0b1000; // 1:256
    T0CON0bits.T016BIT=1;	//16bit mode	
	
    // it's a good idea to initialise the timer registers so we know we are at 0
    TMR0H=0b00001011;            //writing initial values to TMR0L/H register pair
    TMR0L=0b11011100;
    T0CON0bits.T0EN=1;	//start the timer (Turn timer on/off)
}

/************************************
 * Function to return the full 16bit timer value
 * Note TMR0L and TMR0H must be read in the correct order, or TMR0H will not contain the correct value
************************************/
unsigned int get16bitTMR0val(void)
{
	//add your code to get the full 16 bit timer value here
    unsigned int a=TMR0L; //read TMR0L to update TMR0H
    unsigned int B=TMR0H;
    return (B<<8)+a;
}
