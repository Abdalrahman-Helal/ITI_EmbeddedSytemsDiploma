#include <stdio.h>

void main(void)
{
    int sum=0;
    int number=0;
    int iteration=0;

    printf("Please enter the No. of number you want to enter \n");
    scanf("%d",&iteration);

    for(int i=1; i<=iteration;i++)
    {
      printf("please enter number %d\n",i);
      scanf("%d",&number);
      sum+=number;
    }
    
    printf("the summtion is %d",sum);
}