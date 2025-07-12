#include <stdio.h>

int summtion(int *ptr, int *ptr2)
{
    return  *ptr+*ptr2;
}
void main(void)
{
    int x,y;
    printf("Please Enter the 1st Number : \n");
    scanf("%d",&x);
    printf("Please Enter the 2nd Number : \n");
    scanf("%d",&y);

    printf("the summtion is %d",summtion(&x,&y));

}