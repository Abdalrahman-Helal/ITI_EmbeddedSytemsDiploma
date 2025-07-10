#include <stdio.h>

void main(void)
{
    int x = 15; 
    int y = 20;

    int and , or , xor , RShift , LShift ;

    and = x&y;
    or = x|y; 
    xor = x^y;
    RShift = x>>y;
    LShift = x<<y; 

    printf("And = %d , or=%d , xor=%d , RShift=%d , LShift=%d",and , or , xor , RShift , LShift);


}