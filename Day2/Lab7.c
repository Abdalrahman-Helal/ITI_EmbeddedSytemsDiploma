#include <stdio.h>

void main(void)
{
    int number=0;
    int ref;

    printf("Please Enter Refrence Number\n");
    scanf("%d",&ref);

    printf("Please Enter Number Less than %d \n",ref);
    scanf("%d",&number);

    while(number >=ref)
    {   
        printf("Please Enter Number Less than %d 0\n",ref);
        scanf("%d",&number);
    }
  
}