#ifndef _card_H
#define _card_H

#include <xc.h>
#include "lights.h"
#include "color.h"


#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

#define PINKbluethreshold 25
#define ORANGEgreenthreshold 25
#define YELLOWgreenthreshold 50

#define PINKredthreshold 25
#define LIGHTBLUEbluethreshold 25

#define YELLOWredthreshold 50

unsigned char ReturnFLAG=0;

unsigned int red;
unsigned int blue;
unsigned int green;
unsigned int clear;

unsigned char readcard(void);
void levels(int i);

#endif
