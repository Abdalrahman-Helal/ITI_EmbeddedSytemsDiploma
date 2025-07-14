#include <stdio.h>

void main (void)
{
    int degree;
    printf("Please enter your degree\n");
    scanf("%d",&degree);
  
    if(degree > 0 && degree <50)
    {
        printf("Failed");
    }
    else if(degree>=50 && degree <65)
    {
        printf("Pass");
    }
    else if (degree>=65 && degree <75)
    {
        printf("Good");
    }

    else if(degree >=75 && degree <85)
    {
        printf("Very Good");
    }
   else if(degree >=85 && degree <=100) 
   {
    printf("Excellent");
   }
   else
   {
    printf("wrong input");
   }


}