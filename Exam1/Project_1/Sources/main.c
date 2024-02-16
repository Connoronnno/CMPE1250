/********************************************************************/
// HC12 Program:  Exam 2 - Button nd led timing demo
// Processor:     MC9S12XDP512
// Bus Speed:     12 MHz
// Author:        Connor Marsh
// Details:       executes button interface led demo while preserving timing of red led               
// Date:          02/16/24
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "../../lib/SWLED.h" /*used functions and enums for my led switching and button checking */
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
 unsigned int i=0;
 unsigned int buttonCount = 0;
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
   PT1AD1 = 0b11100000;
  /********************************************************************/
	// main program loop
  /********************************************************************/

	for (;;)
	{
	  
    SWL_ON(0b10000000);
     /*arrived at 1ms = 1333 for unsigned int loop delay in ICA4, 1333*15=15ms */
		for (i = 0; i <= 15*1333; i++){	} 
    SWL_OFF(0b10000000);
     /*arrived at 1ms = 1333 for unsigned int loop delay in ICA4, 1333*5=5ms */
    for(i=0; i <= 5*1333; i++){
    }
    
    //counts how many buttons are pressed
    buttonCount = 0;
    if(SWL_PUSHED(SWL_CTR)){
       buttonCount++;
    }
    if(SWL_PUSHED(SWL_UP)){
      buttonCount++;
    }
    if(SWL_PUSHED(SWL_DOWN)){
      buttonCount++;    
    }
    if(SWL_PUSHED(SWL_RIGHT)){
      buttonCount++;
    }
    if(SWL_PUSHED(SWL_LEFT)){
      buttonCount++; 
    }
    
    //switches between yellow and green if total buttons pushed is 2
    if(buttonCount==2){
      SWL_ON(0b00100000);
      SWL_OFF(0b01000000); 
    } 
    else{
      SWL_OFF(0b00100000);
      SWL_ON(0b01000000);
    }
	}
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
