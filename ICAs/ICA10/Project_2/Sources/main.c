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
/********************************************************************/
unsigned int i;
unsigned char byt;
unsigned int pos;
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
  Segs_8H(0, 0x40);
  Segs_8H(7, 14);
  Segs_Normal(4, '3', Segs_DP_OFF);
  Segs_Custom(1, 0b01001010);
  Segs_Custom(2, 0b11110000);
  Segs_Custom(6, 0b10110001);
  Segs_Custom(5, 0b10001011);
  Clock_Set20MHZ();
  byt = 0b11000000;
  pos=0;
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
  
    if(SWL_PUSHED(SWL_CTR)){
    Segs_16H(i, 1);
    Segs_16H(0xffff-i, 0);
    i++;
    RTI_Delay_ms(100);
    }
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
