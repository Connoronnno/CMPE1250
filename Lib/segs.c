#include "segs.h"
#include "stdlib.h"
#include "derivative.h"


#define Segs_WLATCH PORTA &=(~0x01); PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;

void Segs_Init(void){
    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB = 0xff;
}

void Segs_Normal (unsigned char Addr, unsigned char Value, Segs_DPOption dp){

Addr &= 0x07;
Addr |= 0b01011000;
if(dp){
Value &= (~0x80);
}
else{

Value |= 0x80;
}
PORTB = Addr;
Segs_MH

Segs_WLATCH

PORTB=Value;
Segs_ML

Segs_WLATCH
}

void Segs_Custom(unsigned char Addr, unsigned char Value){

Addr &= 0x07;
Addr |= 0b01111000;
PORTB = Addr;
Segs_MH

Segs_WLATCH
PORTB=Value;
Segs_ML
Segs_WLATCH

}

void Segs_Clear(){
Segs_Custom(7, 0b10000000);
Segs_Custom(6, 0b10000000);
Segs_Custom(5, 0b10000000);
Segs_Custom(4, 0b10000000);
Segs_Custom(3, 0b10000000);
Segs_Custom(2, 0b10000000);
Segs_Custom(1, 0b10000000);
Segs_Custom(0, 0b10000000);
}
void Segs_8H(unsigned char Addr, unsigned char Value)  {
Addr&=0x06;
Segs_Normal(Addr, (Value>>4)&0b00001111, Segs_DP_OFF);
Segs_Normal(Addr+1, Value&0b00001111, Segs_DP_OFF);
}
void Segs_16H(unsigned int Value, Segs_LineOption so)  {
if(so){
  
Segs_Normal(0, (Value>>12)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(1, (Value>>8)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(2, (Value>>4)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(3, Value&0b0000000000001111, Segs_DP_OFF);  
} else{
Segs_Normal(4, (Value>>12)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(5, (Value>>8)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(6, (Value>>4)&0b0000000000001111, Segs_DP_OFF);
Segs_Normal(7, Value&0b0000000000001111, Segs_DP_OFF);  
}
}