/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

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
int i = 0;
int j = 0;

for(i=0;i<=255;i++)
{
for(j=0;j<=255;j++)
{
printf("Answer = %d\n", custom_eon(i, j));
}
}


return 0;
}
