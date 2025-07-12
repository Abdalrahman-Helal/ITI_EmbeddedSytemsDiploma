#include <stdio.h>

// int function(int *num1, int *num2)
// {
//     int temp = *num1;
//     *num1 = *num1 + *num2;
//     *num2 = temp - *num2;
// }
// void main(void)
// {
//     int  num1 ,num2;
//     printf("Please Enter the 1st Number : ");
//     scanf("%d",&num1);
//     printf("Please Enter the 2nd Number : ");
//     scanf("%d",&num2);

//     function( &num1, &num2 );
//     printf("the summtion is %d \n", num1);
//     printf("the subtraction is %d \n", num2);
// }

int* func()
{
    int x = 5; // allocate in func
    return &x;
}

int main(void)
{
    int *p = func(); //adress 0x00
    printf("%d",p);
}


