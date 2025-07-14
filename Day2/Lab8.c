#include <stdio.h>

void main(void)
{
    int number=0; 
    printf("Please Enter Numeber : ");
    scanf("%d",&number);
    
    while(number>=0)
    {
         printf("%d\n",number--);
    }
}