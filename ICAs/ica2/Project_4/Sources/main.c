/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     12 MHz
// Author:        Connor Marsh
// Details:       Alternates between red and green leds, biased to green, using a uint16 counter. Migrated from c#            
// Date:          01/19/24
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines 
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED (unsigned int bOn);
void GREEN(unsigned int bOn);
/********************************************************************/
// Global Variables
/********************************************************************/
  unsigned int uiMainLoopCount = 0;
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
  PT1AD1 &= 0x1F;
  DDR1AD1 = 0xE0;     

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
                     ++uiMainLoopCount;
                RED(uiMainLoopCount);
                GREEN(uiMainLoopCount);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void RED (unsigned int bOn)   //changes the PT1AD1 register to turn on the red led when the counter is less than 0x1000, and make sure it's turned off if not
    {
        if (bOn<0x1000)  {
          
                PT1AD1 |= 0b10000000;   
        }
            else
            {
                PT1AD1 &= 0x7F;
            }

        }

void GREEN(unsigned int bOn) //changes the PT1AD1 register to turn on the green led when the counter is 0x1000 or higher, and make sure it's turned off if not
        {
            if (bOn >= 0x1000)
            {
                PT1AD1 |= 0x20;
            }
            else
            {
                PT1AD1 &= 0b11011111;
            }
                            
        }
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
