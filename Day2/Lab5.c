#include <stdio.h>

void main(void)
{
    for(int x=0; x<=10;x++)
    {
        if(x%2==0)
        {
            printf("%d is Even\n",x);
        }
        else
        {
            printf("%d is Odd\n",x);
        }
    }
}