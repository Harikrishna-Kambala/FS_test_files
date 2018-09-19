/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>

int nvdotp(int a, int b){

int res = 0;

__asm__("MOV X9, 0");

__asm__("MOV X1, %[val1]"
    :
    : [val1] "r" (a)
    );

__asm__("MOV X3, %[val3]"
    :
    : [val3] "r" (b)
    );

//load_kernel(32);//just a value that I have initialized temporarily
//Call load_kernel inside of main

__asm__(".long 0x80010C49"
    );

__asm__("MOV %[result], X9"
    : [result] "=r" (res)
    :
    );

return res;

}

void load_kernel(int value){

__asm__("MOV X2, %[kernel_value]"
    :
    : [kernel_value] "r" (value)
    );

}

int main()
{
int result = 0;
load_kernel(31);
result = nvdotp(13, 7);
printf("result = %d",result);

return 0;
}
