#include <xc.h>
#include "lights.h"

void LightInit(void){
    TRISGbits.TRISG1=0; //Red light
    TRISFbits.TRISF7=0; //Blue light
    TRISAbits.TRISA4=0; //Green ligt
    LATGbits.LATG1=0; //Red light
    LATFbits.LATF7=0; //Blue light
    LATAbits.LATA4=0; //Green ligt
}


void Light(unsigned char colorcode){
    if (colorcode==0){ //White light
        LATGbits.LATG1=1; //Red light
        LATFbits.LATF7=1; //Blue light
        LATAbits.LATA4=1; //Green ligt
    }
    if (colorcode==1){ //Red light
        LATGbits.LATG1=1; //Red light
        LATFbits.LATF7=1; //Blue light
        LATAbits.LATA4=0; //Green ligt
    }
    if (colorcode==2){ //Blue light
        LATGbits.LATG1=0; //Red light
        LATFbits.LATF7=1; //Blue light
        LATAbits.LATA4=0; //Green ligt
    }
    if (colorcode==3){ //Green ligt
        LATGbits.LATG1=0; //Red light
        LATFbits.LATF7=0; //Blue light
        LATAbits.LATA4=1; //Green ligt
    }
}