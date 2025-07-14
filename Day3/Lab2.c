#include <stdio.h>

void main(void)
{
    float sum ,num , avg;
    
    for(int i=0; i<5; i++)
    {
        printf("Please Enter Numebr %d : ",i+1);
        scanf("%f",&num);
        sum+=num;   
    }

    avg =(float) sum / 5.0;
    printf("The Average of number is : %0.2f",avg);
}