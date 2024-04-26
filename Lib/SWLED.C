#include "../../../lib/SWLED.h"
#include "derivative.h"
#include "rti.h"


void SWL_Init(){
    PT1AD1 = 0b00000000;
    DDR1AD1 = 0b11100000;
    ATD1DIEN = 0b00011111;
}
void SWL_ON(SWL_LEDColour led){
    PT1AD1 |= led;
}

void SWL_OFF(SWL_LEDColour led){
    PT1AD1 &= ~led;
}

void SWL_TOG(SWL_LEDColour led){
    PT1AD1 ^= led;
}

unsigned int SWL_PUSHED(SWL_SwitchPos pos){
    return PT1AD1&pos;
    }

int SWL_ANY(){
    return PT1AD1&0b00011111>0;
    }
