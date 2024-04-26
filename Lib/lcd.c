#include "lcd.h"
#include "stdlib.h"
#include "derivative.h"
#include "rti.h"
#include "SWLED.h"

void lcd_Init (void){

if(!(CRGINT&0b10000000)){
    RTI_Init();
}
PTH =0b00000000;
DDRH = 0b11111111;
PORTK &=0b11111000;
DDRK|=0b00000111;
RTI_Delay_ms(50);
PTH = 0b00111000;
PORTK|=0b00000001;
PORTK&=0b11111000;
RTI_Delay_ms(5);
PORTK|=0b00000001;
PORTK&=0b11111000;
RTI_Delay_ms(1);
PORTK|=0b00000001;
PORTK&=0b11111000;
RTI_Delay_ms(1);
lcd_Ins(0b00111000);
lcd_Ins(0b00001110);
lcd_Ins(0b00000001);
lcd_Ins(0b00000110); 
}

void lcd_Ins(unsigned char val){
    while(lcd_Busy()!=0);
    PTH=val;
    PORTK|=0b00000001;
    PORTK&=0b11111000;
 
    
}
void lcd_Data(unsigned char val){
    while(lcd_Busy()!=0);
    if(val==0){
    val=0x30;
    } 
    else if(val==1)  {
     val=0x31; 
    }
    else if(val==2)  {
     val=0x32; 
    }
    else if(val==3)  {
     val=0x33; 
    }
    else if(val==4)  {
     val=0x34; 
    }
    else if(val==5)  {
     val=0x35; 
    }
    else if(val==6)  {
     val=0x36; 
    }
    else if(val==7)  {
     val=0x37; 
    }
    else if(val==8)  {
     val=0x38; 
    }
    else if(val==9)  {
     val=0x39; 
    }
    else if(val==10)  {
     val=0x41; 
    }
    else if(val==11)  {
     val=0x42; 
    }
    else if(val==12)  {
     val=0x43; 
    }
    else if(val==13)  {
     val=0x44; 
    }
    else if(val==14)  {
     val=0x45; 
    }
    else if(val==15)  {
     val=0x46; 
    }
    PTH=val;
    PORTK|=0b00000101;
    PORTK&=0b11111000;
}
void lcd_Addr(unsigned char Addr){
  Addr|=0b1000000;
  lcd_Ins(Addr);
}
void lcd_Pos(unsigned char cRow, unsigned char cCol){
     if(cRow>3||cCol>19){
     lcd_Addr(0);
     } 
     else{
     switch(cRow){
      case 0:
      lcd_Addr(cCol);
      case 1:
      lcd_Addr(cCol+64);
      case 2:
      lcd_Addr(cCol+20);
      case 3:
      lcd_Addr(cCol+84);
      SWL_ON(SWL_YELLOW);
     }
     }
     
}
void lcd_String(char const* string){

  while(*string!=0) lcd_Data(*string++);
}
unsigned char lcd_Busy(void){
unsigned char val;
DDRH= 0b00000000;
  PORTK|=0b00000011;
  PORTK&=0b11111000;
  val=PTH&0b10000000;
  DDRH=0b11111111;
  return val;
}