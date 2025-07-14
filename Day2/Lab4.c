#include <stdio.h>

void main(void)
{
    int ID; 
    printf("Please enter your ID :");
    scanf("%d",&ID);

    // switch(ID)
    // {
    //     case 1234:
    //         printf("Welcome Ahmed");
    //         break;
        
    //     case 5677:
    //         printf("Welcome Yousef");
    //         break;

    //     case 1145:
    //         printf("Welcome Mina");
    //         break;

    //     default:
    //         printf("Wrong Input");
    //         break;
    // }

    (ID == 1234) ? printf("Welcome Ahmed") : 
    (ID == 5677) ? printf("Welcome Yousef") : 
    (ID == 1145) ? printf("Welcome Mina") : 
    printf("Wrong Input");
}
