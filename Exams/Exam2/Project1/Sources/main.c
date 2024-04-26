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
#include <stdlib.h>
#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/

unsigned int tenths = 0;
char str[2];
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
sci0_InitMath(20000000, 38400);
RTI_Init();
Clock_Set20MHZ();
Segs_Init();
Segs_Clear();
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {      
      sprintf(str, "%d", tenths/6000);
      tenths++;
      Segs_Clear();
      if(tenths<9999){
        
      Segs_16D(tenths, 1);  
      }
      
     sci0_txStr("\x1b[5;37H");
     sci0_txByte('0');
     sci0_txStr(str);
     sprintf(str, "%d", tenths/10);
     sci0_txByte(':');
     sci0_txStr(str);
      sci0_txByte(':');
     sprintf(str, "%d",tenths%10);
     sci0_txStr(str);
     RTI_Delay_ms(100);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
