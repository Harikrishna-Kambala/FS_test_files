/*
 * Licence etc etc
 * Authors:
 */
#include <stdio.h>

int test_eon(int a, int b){
int res = 0;
__asm__("EON %[result], %[in1], %[in2]"
        :[result] "=r" (res)
        :[in1] "r" (a), [in2] "r" (b)
        );
return res;
}

int main()
{
int num1=1, num2=255;
printf("Testing the XNOR operation \n");
printf("Answer = %d", test_eon(num1,num2));
return 0;
}
