/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

int dotp(int kernel_index, int value)
{
int res = 0;
//I'll assume that Rd is always X9, and initially set it to 0;
__asm__("MOV X9, 0");

//Store Rm at X1.
__asm__("MOV X1, %[val1]"
	:
	: [val1] "r" (kernel_index)	
	);

//Store Rn at X2.
__asm__("MOV X2, %[val2]"
	:
	: [val2] "r" (value)
	);

__asm__(".long 0xC0210C49"
    );
__asm__("MOV %[result], X9"
	: [result] "=r" (res)
	:
	);

return res;
}

int main()
{
	int i=0;
	
	printf("Answer = %d\n", dotp(4, 4));
	return 0;
}
