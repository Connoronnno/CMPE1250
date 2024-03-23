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
 unsigned char a;
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
SWL_Init();
SCI0_Init();
RTI_Init(); 
Clock_Set20MHZ();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
      //blinking led
      RTI_Delay_ms(50);
      SWL_TOG(SWL_RED);
      
      //sends random char
      a=(unsigned char)GetRandom(65, 91);
      sci0_txByte(a);
      
      //checking sent and recieved data for vowels
      if(sci0_read(&a)) SWL_ON(SWL_YELLOW);
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){
         SWL_OFF(SWL_YELLOW);         SWL_ON(SWL_GREEN);
        } 
        else{
         SWL_OFF(SWL_GREEN);
         SWL_ON(SWL_YELLOW);
        }
      
      
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
