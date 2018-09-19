/*
 * License etc etc
 * Authors:
 */

#include <stdio.h>

int madd1(int a, int b, int c)
{
int res = 0;
//The format is MADD <Xd>, <Xn>, <Xm>, <Xa>;
__asm__("MADD %[result], %[in1], %[in2], %[in3]"
	:[result] "=r" (res)
	:[in1] "r" (a), [in2] "r" (b), [in3] "r" (c)
	);
return res;
}

int main()
{
int num1=10,num2=12,num3=3;
printf("This is a test of a simple inline MADD operation.\n");
printf("The output should be 123 (=(10 * 12) + 3)");

printf("Answer = %d",madd1(num1, num2, num3));
return 0;
}
