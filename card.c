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
    
    float ratio1=colorL->R/colorL->B;
    float ratio2=colorL->R/colorL->G;
    float ratio3=colorL->B/colorL->G;
    
    //BLUE OR LIGHT BLUE
    if ((ratio1>80 & ratio1<125) & (ratio2>80 & ratio2<125) & (ratio3>80 & ratio3<125)){
        if(colorL->B>4000){return 7;} //Light blue
        return 2; //blue
    }
    
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
    //DIFFERENTIATE WHITE AND GREEN
    levels(1,colorL);
    if(colorL->R>1000){return 0;}
    return 3;
}

void levels(int i,struct RGB_val *colorL){
        Light(i);
        __delay_ms(900);
        if (i==1){LATFbits.LATF7=1;}
        colorL->R = color_read_Red();
        colorL->B = color_read_Blue();
        colorL->G = color_read_Green();
}