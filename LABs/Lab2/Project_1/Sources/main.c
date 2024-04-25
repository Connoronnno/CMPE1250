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
  unsigned int i = 0;
  unsigned int c =0;
  unsigned char select = 1;
  unsigned int ii = 0;
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
  Segs_16D(100, 1);
  Clock_Set20MHZ();

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
   i++;
   RTI_Delay_ms(50);
   SWL_TOG(SWL_RED);
   if(i>=20){
   SWL_TOG(SWL_GREEN);
   i=0;
   c++;
   }
   if(SWL_PUSHED(SWL_UP)){
   select=0;
   }
   if(SWL_PUSHED(SWL_DOWN)){
   select=1;
   }
   if(select){
   Segs_16D(c, 1); 
   } 
   else{
   Segs_16H(c, 1);
   }
   if(c>9999||SWL_PUSHED(SWL_CTR)){
   c=0;
   }
   if(i%4==0){
      for(ii=0; ii<((i+4)/4);ii++){
        Segs_Custom(4+ii, 0b00000000); 
        if(ii>3){
        Segs_Custom(4, 0b10000000);
        Segs_Custom(5, 0b10000000);
        Segs_Custom(6, 0b10000000);
        Segs_Custom(7, 0b10000000);
        }
      }
   }
   }
  }                   


/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
