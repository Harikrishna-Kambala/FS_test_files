/*
 * License etc etc
 * Authors:
 */

#include <stdio.h>

int EON(int a, int b)
{
int res = 0;
//The format is EON <Xd>, <Xn>, <Xm>;
__asm__("EON %[result], %[in1], %[in2]"
	:[result] "=r" (res)
	:[in1] "r" (a), [in2] "r" (b)
	);
return res;
}

int main()
{
int num1=10,num2=12,num3=3;
printf("This is a test of a simple inline MADD operation.\n");
printf("The output should be 123 (=(10 * 12) + 3)");

printf("Answer = %d", EON(num1, num2));
return 0;
}
