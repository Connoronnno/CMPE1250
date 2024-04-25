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
  unsigned int upperVal =0;
  unsigned int upperVal2=0;
  unsigned int addr=0;
  unsigned int mult=1;
  unsigned int i;
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
  Segs_Init();
  SWL_Init();
  RTI_Init();
  Segs_Clear();
  Clock_Set20MHZ();

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
      RTI_Delay_ms(50);
      for(i=0;i<addr;i++){
      mult *=10;
      }

      if(SWL_PUSHED(SWL_UP)){
      if((upperVal%(mult/10))>=9){
         upperVal-=(upperVal%(mult/10));
      }
      else{
        
      upperVal += mult;
      }
      }
      if(SWL_PUSHED(SWL_DOWN)){
      if((upperVal%(mult/10))<=0){
         upperVal+=9-(upperVal%(mult/10));
      } 
      else{
      upperVal -= mult;
      }
      }
      if(SWL_PUSHED(SWL_LEFT)){
      if(addr<3){
        addr+=1;
      }
      }
      if(SWL_PUSHED(SWL_RIGHT)) {
      if(addr>0){
        addr-=1;
      }
      } 
      if(upperVal2!=upperVal){
        
      Segs_16D(upperVal, 1);
      Segs_16H(upperVal, 0);  
      } 
      upperVal2=upperVal;
      mult=1;  
  }                  

}
/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
