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
unsigned int i=0;
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
     if(SWL_PUSHED(SWL_LEFT)){
         Clock_Set8MHZ();
    } 
    else if(SWL_PUSHED(SWL_CTR)){
        Clock_Set20MHZ();
    } 
    else if(SWL_PUSHED(SWL_RIGHT)){
        Clock_Set24MHZ();
    }
  for (;;)
  {
    SWL_TOG(SWL_RED);
    for(i=0; i<=(1333*20); i++ ){
    }
     for(i=0; i<=(1333*20); i++ ){
    }
    for(i=0; i<=(1333*20); i++ ){
    }
    for(i=0; i<=(1333*20); i++ ){
    }
    for(i=0; i<=(1333*20); i++ ){
    }
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
