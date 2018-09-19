/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

int custom_madd1(void)
{
int res = 10;
//".long 0x010C0D49" This is what I wanted to first try, failed.
//".long 0x1B000C01" This works, but it squares the input.dont know why.

/* Xd = Value at register pointed by Xm*Xn + Xa;
 */

//I'll assume that Rd is always X9, and initially set it to 0;
__asm__("MOV X9, 0");

//I'll store Rm at X1.
__asm__("MOV X1, 0");//storing a value of 0 at X1.
//I'll store Rn at X2.
__asm__("MOV X2, 0");//storing a value of 0 at X2.
//I'll store Ra at X3.
__asm__("MOV X3, 10");//storing a value of 0 at X3.


__asm__(".long 0x11010C49"
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
//int i = 10;
//int answer = 0;
//for(i = 10;i<=100;i++)
{
//answer = i;
//answer = custom_madd1();
printf("Answer = %d\n", custom_madd1());
}
printf("Exiting main\n");
return 0;
}
