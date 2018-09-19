/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>
#include <stdlib.h>

int custom_bitcount(int a)
{
//printf("The value passed = %x\n",a);
int count = 0;
int var=0;
//while(a <= 0xFFFFFFFF)
while(var < 32)
{
//printf("The value of a inside the while loop = %x\n",a);
if(a%2 != 0) { count = count + 1; }
a = a>>1;
var++;
}

return count;
}
/////////////////////////////////////////////////////////////////////////////////
int custom_eon(int a, int b)
{
int res = 0;
//I'll assume that Rd is always X9, and initially set it to 0;
__asm__("MOV X9, 0");

//Store Rm at X1.
__asm__("MOV X1, %[val1]"
	:
	: [val1] "r" (a)	
	);

//Store Rn at X2.
__asm__("MOV X2, %[val2]"
	:
	: [val2] "r" (b)
	);

__asm__(".long 0xC0210049"
	);

__asm__("MOV %[result], X9"
	: [result] "=r" (res)
	:
	);

return res;
}
/////////////////////////////////////////////////////////////////////////////////


int main()
{
int i = 0;//set your inputs here
int j = 0;//set your second input here
//int xnor1 = custom_eon(i, j);
//int bitcount = custom_bitcount(xnor1);
for(i=0;i<=255;i++)
{
for(j=0;j<=255;j++)
{
printf("XNOR = %x		Bitcount = %d\n", custom_eon(i, j), custom_bitcount(custom_eon(i, j)));
}
}
//printf("Bitcount = %d\n",custom_bitcount(custom_eon(i, j)));
return 0;
}
