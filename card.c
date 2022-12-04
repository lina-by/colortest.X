#include <xc.h>
#include "card.h"
#include "lights.h"
#include "color.h"
#include "i2c.h"

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
 * black = 8
 **********************************/


unsigned char readcard(struct RGB_val *colorL){
    levels(0,colorL);
    //BLACK
    if(colorL->R+colorL->G+colorL->B<1000){return 8;}
    //BLUES
    if (colorL->R<1.3*colorL->G & colorL->R<1.3*colorL->B){return 2;}
    if (colorL->R<1.6*colorL->G & colorL->R<1.6*colorL->B){return 7;}
    
    //GREEN
    if (colorL->R<colorL->G){return 3;}
    
    // RED ORANGE PINK YELLOW
    if (colorL->R>colorL->B*1.6 & colorL->R>colorL->G*1.6){ //red, orange, pink, yellow
        //test for pink
        levels(2,colorL);
        if(colorL->B>2*colorL->R){return 4;}
        // test for yellow
        levels(3,colorL);
        if(colorL->G>3.8*colorL->R){return 5;}
        // test for orange
        if(colorL->G>2*colorL->R){return 6;}
        
        //Otherwise return red
        return 1;
    }
    return 0;
}

void levels(int i,struct RGB_val *colorL){
        Light(i);
        __delay_ms(900);
        if (i==1){LATFbits.LATF7=1;}
        colorL->R = color_read_Red();
        colorL->B = color_read_Blue();
        colorL->G = color_read_Green();
}