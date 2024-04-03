#include "misc.h"
#include "stdlib.h"
#include "derivative.h"

int GetRandom(int iLow, int iHighEx){
    return (iLow+(rand()%(iHighEx-iLow)));
}

unsigned char GetRandomChar(void){
 unsigned char a=(unsigned char)GetRandom(65, 91); 
 return a;
}

unsigned char* GetRandomString(unsigned int length, unsigned char* a, unsigned int upperlower){
  unsigned int i;
  unsigned char c;
  unsigned char uppers[5] = "AEIOU";
  unsigned char lowers[5]  = "aeiou";
  for(i=0; i<length; i++){
  if(!upperlower){
    c = lowers[GetRandom(0, 5)];
  } 
  else{
    c=uppers[GetRandom(0, 5)];
  }
  a[i] = c;
  }
  return a;}