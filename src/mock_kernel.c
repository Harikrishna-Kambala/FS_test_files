/*
 * Licence etc etc
 * Authors:
 */

#include <stdio.h>


int binarydotP(int value, int kernel_number){

	int res=0;
	//So I just need to load a value at X2=Rn here
	__asm__("MOV X1, %[val2]"
    	:
    	: [val2] "r" (value)
    	);
	__asm__("MOV X2, %[index]"
        :
        : [index] "r" (kernel_number)
        );

	//Now perform xnor+bitcount
	__asm__(".long 0xC0210C49");
	//Load result into X9
	__asm__("Mov %[result], X9"
    	: [result] "=r" (res)
    	:
    	);
	return res;
}

int main(){

	//int i = 17;
	//printf("The answer = %d\n",binarydotP(13, 0));
	//printf("The answer = %d\n",binarydotP(11, 1));
    //printf("The answer = %d\n",binarydotP(99, 2));
    //printf("The answer = %d\n",binarydotP(20, 3));
    printf("The answer = %d\n",binarydotP(1, 4));
	return 0;
}
