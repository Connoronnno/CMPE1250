/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "rti.h"
#include "SWLED.h"
#include "sci.h"
#include "clock.h"
#include "segs.h"
#include "lcd.h"
//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int randInt;
unsigned char sciVal;
unsigned int lowerVal;
unsigned int tempVal;
unsigned int mult=1;
unsigned int addr=4;
unsigned int i=0;
unsigned char onegood = 0;
unsigned char twogood = 0;
unsigned char threegood = 0;
unsigned char fourgood = 0;
unsigned int checkVal=10;
unsigned int oCheckVal=0;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
SWL_Init();
sci0_InitMath(20000000, 9600);
RTI_Init();
Clock_Set20MHZ();
randInt = GetRandom(0,9999);
Segs_Init();
Segs_Clear();
Segs_16D(randInt, 1);

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
      while(addr<=7){
      Segs_16D(randInt, 1);
      if(sci0_read(&sciVal)){
      Segs_16D(randInt, 1);
      if(sciVal=='0'){
      checkVal=0;
      }
      if(sciVal=='1'){
      checkVal=1;
      }
      if(sciVal=='2'){
      checkVal=2;
      }
      if(sciVal=='3'){
      checkVal=3;
      }
      if(sciVal=='4'){
      checkVal=4;
      }
      if(sciVal=='5'){
      checkVal=5;
      }
      if(sciVal=='6'){
      checkVal=6;
      }
      if(sciVal=='7'){
      checkVal=7;
      }
      if(sciVal=='8'){
      checkVal=8;
      }
      if(sciVal=='9'){
      checkVal=9;
      }
      Segs_Normal(addr, checkVal, 0);
      if(addr==4){
      oCheckVal=(randInt/1000)&0b0000000000001111; 
      if(oCheckVal==checkVal){
      SWL_ON(SWL_GREEN);
        onegood=1;
      }
      }
      if(addr==5){
      oCheckVal=(randInt/100)&0b0000000000001111; 
      if(oCheckVal==checkVal){
      SWL_OFF(SWL_GREEN);
        twogood=1;
      }   
      }
       if(addr==6){
        oCheckVal=(randInt/10)&0b0000000000001111;
        if(oCheckVal==checkVal){
       SWL_OFF(SWL_GREEN);
        threegood=1;
      }    
       }
      if(addr==7)  {
      oCheckVal=(randInt)&0b0000000000001111;  
      if(oCheckVal==checkVal){
      SWL_OFF(SWL_GREEN);
      
       fourgood=1;
       } 
      }
       if(fourgood&&onegood)  addr++;
      
      if(checkVal!=10){
      addr++;
      }
     checkVal=10;
      }
      }
      RTI_Delay_ms(2000);
      randInt = GetRandom(0,9999);
      addr=4;
      checkVal=10;
      onegood=0;
      fourgood=0;
      Segs_Clear();
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
