/*
* Licence etc etc
* Authors:
*/

#include <stdio.h>

int addition(int in1)
  {
    int res = 0;
    __asm("MOV X9, %[input_i]"
		:
		: [input_i] "r" (in1)
	);
    __asm (".long 0x01000D29" 
    );
   __asm("MOV %[result], X9"
                : [result] "=r" (res)
                : 
	);
    return res;
  }

int main()
{

   //printf("Entered Main\n");
   int i=0;
   int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
   

   int C[10];

   //printf("Entering Loop\n");	
    
   for (i=0; i<10; i++)
	{ 
	  C[i] = addition (A[i]);	
          
          printf ("C[%d] = %d\n", i, C[i] );
	}



}

