#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d"
void print_array(int n, DATA_TYPE outArray[])
{
 for(int i=0; i<n; i++)
 {
  printf(DATA_PRINTF_MODIFIER, outArray[i]);
  if((i+1)%20==0)
  {
   printf("\n");
  }
 }
}
