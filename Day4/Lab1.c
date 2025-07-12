#include <stdio.h>

void main(void)
{
    int x = 5; 
    int *ptr = &x; 


    
    
    printf("the value of X before  %d\n",x);   
    
    *ptr = 10;
    printf("the value of X before %d",x);
    
    // printf("the value of X %d\n",x);
    // printf("the address of x %p\n",&x);
    // printf("the value inside address of pointer %d\n",*ptr);
    // printf("the address of ptr %p\n",&ptr);
    // printf("the address of x %p",ptr);

}