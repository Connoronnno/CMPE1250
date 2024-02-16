/********************************************************************/
// HC12 Program:  ICA5-SwitchDemo
// Processor:     MC9S12XDP512
// Bus Speed:     45 MHz
// Author:        Connor Marsh
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "SWLED.h" /* SWL library */
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

ATD1DIEN1 = 0b00011111;
DDR1AD1 = 0b1110000;
PT1AD1 = 0b00000000;
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    if(SWL_PUSHED(0b00001000)){
      SWL_ON(0b10000000);
    }
    else if(SWL_PUSHED(0b00000001)){
      SWL_ON(0b01000000);
    }
    else if(SWL_PUSHED(0b00000010)){
      SWL_ON(0b00100000);
    }
    SWL_OFF(0b00000000);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
