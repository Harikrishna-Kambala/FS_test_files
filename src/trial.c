/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

int custom_madd1(int a, int b, int c)
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

//Store Ra at X3.
__asm__("MOV X3, %[val3]"
	:
	: [val3] "r" (c)
	);

/*
__asm__(".long 0x1b010C49"
	);
*/

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
//printf("Entered main\n");
//printf("This function implements i^2 + i, for i from 0 to 10\n");
//int i = 13;
//for(i = 0;i<=10;i++)
//{
printf("%d\n",custom_madd1(110, 131, 1141));
//printf("Answer = %d\n", custom_madd1(0, 3, 14));
//}
//printf("Exiting main\n");
return 0;
}
