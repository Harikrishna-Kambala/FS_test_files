/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

int custom_madd1(int a, int b, int c)
{
int res = 0;
__asm__("MOV X9, 0");

__asm__("MOV X1, %[val1]"
	:
	: [val1] "r" (a)	
	);

__asm__("MOV X2, %[val2]"
	:
	: [val2] "r" (b)
	);

__asm__("MOV X3, %[val3]"
	:
	: [val3] "r" (c)
	);

__asm__(".long 0x80010C49"
	);

__asm__("MOV %[result], X9"
	: [result] "=r" (res)
	:
	);

return res;
}

int main()
{
printf("Entered main\n");
int i = 0;
for(i = 0;i<=10;i++)
{
printf("Answer = %d\n", custom_madd1(i, i, i));
}
printf("Exiting main\n");
return 0;
}
