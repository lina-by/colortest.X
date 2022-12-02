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
 **********************************/


unsigned char readcard(void){
    levels(0);
    unsigned char white=0;
    unsigned char red=1;
    unsigned char blue=2;
    unsigned char green=3;
    unsigned char pink=4;
    unsigned char yellow=5;
    unsigned char orange=6;
    unsigned char lightblue=7;
    
    unsigned int ratio1=100*red/blue;
    unsigned int ratio2=100*red/green;
    unsigned int ratio3=100*blue/green;
    
    //BLUE OR LIGHT BLUE
    if ((ratio1>80 & ratio1<125) & (ratio2>80 & ratio2<125) & (ratio3>80 & ratio3<125)){
        if(blue>4000){return lightblue;} //Light blue
        return blue; //blue
    }
    
    if (ratio1>160 & ratio2>160){ //red, orange, pink, yellow
        //test for pink
        levels(2);
        if(blue>1000){return pink;}
        // test for yellow
        levels(3);
        if(green>5500){return yellow;}
        // test for orange
        levels(3);
        if(green>2000){return orange;}
        
        //Otherwise return red
        return red;
    }
    //DIFFERENTIATE WHITE AND GREEN
    levels(1);
    if(red>1000){return white;}
    return green;
}

void levels(int i){
        Light(i);
        __delay_ms(900);
        red = color_read_Red();
        blue = color_read_Blue();
        green = color_read_Green();
        clear = color_read_Clear();
}