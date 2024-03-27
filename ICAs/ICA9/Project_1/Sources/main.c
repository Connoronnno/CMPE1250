/********************************************************************/
// HC12 Program:  ICA09
// Processor:     MC9S12XDP512
// Bus Speed:     20 MHz
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
#include "rti.h"
#include "SWLED.h"
#include "sci.h"
#include "clock.h"
#include "stdlib.h"
#include "stdio.h"
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
unsigned char b[22];

unsigned int sum;
unsigned int i;
unsigned int nums;
char str[4];
unsigned char space;

unsigned int aa;
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
sci0_InitMath(20000000, 19200);
RTI_Init();
Clock_Set20MHZ();
nums = 0;
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
   sum=0;
   
   RTI_Delay_ms(250); 
   SWL_TOG(SWL_GREEN);
   if(SWL_PUSHED(SWL_CTR)){
   GetRandomString(20, b, 1);
   nums+=1; 
   } else {
   nums+=1; 
   GetRandomString(20, b, 0); 
   }
   for(i=0; i<20; i++){
   sum += (unsigned int)b[i];
   }
   
   
   sci0_txStr("\x1b[2J");
   
   	
   sci0_txStr("\x1b[0;0H");
   
   sci0_txStr("\x1b[34m");
   sci0_txStr("CONNOR MARSH");
   
   sci0_txStr("\x1b[3;0H");
   
   for(aa = 0; aa>2000; aa++){
   sci0_txStr("\x1b[1D");
   }
   
   sci0_txStr("\x1b[32m");
   sci0_txStr(b);
   
   
   sci0_txStr("\x1b[33m");
   sprintf(str, "%d", sum);
   strcat(str, " ");
   
   sci0_txByte(' ');
   sci0_txStr(str);
   
    sci0_txStr("\x1b[5;0H");
   
   for(aa = 0; aa>2000; aa++){
   sci0_txStr("\x1b[1D");
   }
   
   sprintf(str, "%d", nums);
   
   sci0_txStr("\x1b[37m");
   sci0_txStr(str);
   
}
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
