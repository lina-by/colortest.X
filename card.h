#ifndef _card_H
#define _card_H

#include <xc.h>
#include "lights.h"
#include "color.h"


#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


unsigned char readcard(struct RGB_val *colorL);
void levels(int i,struct RGB_val *colorL);

#endif
