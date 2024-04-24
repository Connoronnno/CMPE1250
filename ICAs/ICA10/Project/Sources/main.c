#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "segs.h"




void main(void) {
  /* put your own code here */
  

  Segs_Init();
  Segs_Clear();
  Segs_16H(65500, 1);
	EnableInterrupts;


  for(;;) {
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
