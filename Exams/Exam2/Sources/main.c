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
 unsigned int i = 0;
 char per = '.';
 unsigned int num = 0;
 unsigned int nnum = 0;
 unsigned char str[5];
  unsigned char strr[5];
 unsigned int zeros = 0;
 unsigned int ii = 0;
 unsigned char strc[14];
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

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
  nnum=num;
  while((nnum%10)>=10){
  zeros++;
  nnum = nnum/10;
  }
  sci0_txStr("\x1b[0;0H");
  sci0_txStr(strc);
  for(ii=0; ii<=zeros; ii++){
  sci0_txByte('0');
  }
  sprintf(str, "%d",num);
  sci0_txStr(str);
  RTI_Delay_ms(10);
  SWL_TOG(SWL_RED);
  if(SWL_PUSHED(SWL_UP)){
  per = '!';
  }
  if(SWL_PUSHED(SWL_DOWN)){
  per = '?';
  }
  if(SWL_PUSHED(SWL_CTR)){
  per = '.';
  }
  sci0_txStr("\x1b[37m");
  sprintf(str, "\x1b[3;%dH",num%100);
  if(i==10){
  sci0_txStr(str);
  sci0_txByte(per);
  SWL_TOG(SWL_GREEN);
  i=0;
  num++;
  } 
  sci0_read(strr);
  if(strr[0]=='r'||strr[0]=='R'){
     sprintf(strc, "\x1b[31m");
  }
  if(strr[0]=='g'||strr[0]=='G'){
    sprintf(strc, "\x1b[32m");
  }
  if(strr[0]=='b'||strr[0]=='B'){
     sprintf(strc, "\x1b[34m");
  }
  i++;
  
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
