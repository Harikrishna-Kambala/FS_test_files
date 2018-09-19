/*
 * Licence etc etc
 * Authors:
 *
 * This is a c++ program that madd's three numbers using inline assembly.
 */

#include <stdio.h>

int madd_inline(int a, int b, int c)
{
int res = 0;
__asm__("MADD %[result], %[in1], %[in2], %[in3]"
	:[result] "=r" (res)
	:[in1] "r" (a), [in2] "r" (b), [in3] "r" (c)
	);
return res;

}

int main()
{

//What we want is result = (num1 * num2) + num3;

int num1 = 10;
int num2 = 12;
int num3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
int i = 0;

for(i=0;i<=9;i=i+1)
{
	printf("Answer = %d\n",madd_inline(num1, num2, num3[i]));
}

return 0;
}
