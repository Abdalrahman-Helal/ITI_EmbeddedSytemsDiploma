#include <stdio.h>

void main(void)
{
    int num=0,factorial=1;

    printf("Please Enter Number : ");
    scanf("%d",&num);

    while(num>0)
    {
        factorial*=num--;
    }
    printf("the factorial is : %d",factorial);
}