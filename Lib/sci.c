#include "rti.h"
#include "derivative.h"
#include "sci.h"

void SCI0_Init(void){
    SCI0CR2 = 0;
    SCI0BD = 130;
    SCI0CR2_RE = 1;
    SCI0CR2_TE = 1;
}

unsigned char sci0_read(unsigned char* pData){
    if(SCI0SR1_RDRF){
        *pData = SCI0DRL;
        return 1;
    }
    else{
        return 0;
    }
}

void sci0_txByte (unsigned char data){
    while(!(SCI0SR1 & SCI0SR1_TDRE_MASK));
    SCI0DRL = data;
}

unsigned long sci0_InitMath(unsigned long ulBusClock, unsigned long ulBaudRate){

    unsigned long divisor = ulBusClock/(16*ulBaudRate);
    SCI0CR2 = 0;
    SCI0BD = divisor;
    SCI0CR2_RE = 1;
    SCI0CR2_TE = 1;
    return divisor;
}

void sci0_txStr(char const * straddr){
    while(*straddr){
        sci0_txByte(*straddr);
        straddr++;
    }
}