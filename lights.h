#ifndef _lights_H
#define _lights_H

#include <xc.h>


#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

#define PINKbluethreshold 25
#define ORANGEgreenthreshold 25
#define YELLOWgreenthreshold 50

#define PINKredthreshold 25
#define LIGHTBLUEbluethreshold 25

#define YELLOWredthreshold 50

void LightInit(void);
void Light(unsigned char colorcode);

#endif
