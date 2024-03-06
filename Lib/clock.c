#include "clock.h"
#include "derivative.h"


void Clock_EnableOutput(ClockOutDiv clockOutDiv){
    CLKSEL &= 0b01111111;
}

void Clock_Set8MHZ(){
    CLKSEL &= 0b01111111;
}//((2*16MHz*(0+1))/(1+1))/2 = 8Mhz

void Clock_Set20MHZ(){  
    CLKSEL &= 0b01111111;
    SYNR = 4;
    REFDV = 3;
    PLLCTL = 0b01100000;
    while(!(CRGFLG & CRGFLG_LOCK_MASK));
    CLKSEL |= 0b10000000;}
//((2*16MHz*(4+1))/(3+1))/2 = 20MHz

void Clock_Set24MHZ(){
    CLKSEL &= 0b01111111;
    SYNR = 2;
    REFDV = 1;
    PLLCTL = 0b01100000;
    while(!(CRGFLG & CRGFLG_LOCK_MASK));
    CLKSEL |= 0b10000000;
}//((2*16MHz*(2+1))/(1+1))/2 = 24MHz
