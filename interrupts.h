#ifndef _interrupts_H
#define _interrupts_H

#include <xc.h>
#include "serial.h"


#define _XTAL_FREQ 64000000
char charFLAG;
char sendFLAG;
void Interrupts_init(void);
void __interrupt(high_priority) HighISR();

#endif
