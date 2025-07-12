#include <stdio.h>

void main(void)
{
    // printf("the size of char %d\n",sizeof(char));
    // printf("the size of int %d\n",sizeof(int));
    // printf("the size of long long int %d\n",sizeof(long long int));
    // printf("the size of float %d\n",sizeof(float));
    // printf("the size of double %d\n",sizeof(double));

    for(int i=0; i<1;i++)
    {
        static int y = 5;
    }
    
    printf("the value of y %d",y);
}