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
unsigned int ms  = 10;
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
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    if(SWL_PUSHED(SWL_UP)) ms=8;
    else if(SWL_PUSHED(SWL_DOWN)) ms=12;
    else ms=10;
    if(SWL_PUSHED(SWL_UP)&&SWL_PUSHED(SWL_DOWN)) ms=10;
    if(SWL_PUSHED(SWL_LEFT)&&!SWL_PUSHED(SWL_RIGHT)){
     SWL_ON(SWL_RED);
        RTI_Delay_ms(1);  
        SWL_OFF(SWL_RED);
        RTI_Delay_ms(9);  
       
    } 
    else if(SWL_PUSHED(SWL_RIGHT)){
        SWL_OFF(SWL_RED);
        SWL_ON(SWL_GREEN);
    }
    else{
             SWL_TOG(SWL_RED);
     RTI_Delay_ms(ms);
    }
    if(!SWL_PUSHED(SWL_RIGHT)) SWL_OFF(SWL_GREEN);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
