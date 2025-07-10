#include <stdio.h>

void main(void)
{
    int num1, num2;
    
    printf("please enter the 1st number\n");
    scanf("%d",&num1);

    printf("please enter the 2nd number\n");
    scanf("%d",&num2);

    int sum= num1 + num2;
    int Mul= num1 * num2;
    float Div= num1 / num2;

    printf("the sum is %d\n",sum);
    printf("the Mul is %d\n",Mul);
    printf("the Div is %0.2f\n",Div);
}