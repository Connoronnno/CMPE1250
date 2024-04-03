#include "rti.h"
#include "derivative.h"

void RTI_Init(void){

    RTICTL = 0b10010111;
    CRGINT |= 0b10000000;


}

void RTI_Delay_ms(unsigned int ms){
    
    CRGINT &= 0b01111111;
    
    for(; ms>0; ms--){
        while(!CRGFLG_RTIF){
        }
        CRGFLG = CRGFLG_RTIF_MASK;
    }

    CRGINT &= 0b01111111;
}