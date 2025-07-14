#include<stdio.h>


// void function()
// {
//     printf("yes you can");
// }


void main(void)
{
    int age;
    printf("Welcome to driving Check system\n");
    printf("please enter your age to check if you can drive or not :");
    scanf("%d",&age);

    (age>=16 && printf("Yes, you can")) || printf("Sorry you can't");
}

