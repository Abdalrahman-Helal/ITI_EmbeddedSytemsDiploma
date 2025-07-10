#include <stdio.h>

void main(void)
{
    int Number , ShiftValue;

    printf("Please Enter the number ");
    scanf("%d",&Number);
    printf("Please Enter the Shift Value");
    scanf("%d",&ShiftValue);

    int RShift = Number>>ShiftValue;
    int LShift = Number<<ShiftValue;

    printf("The RShift = %d , The LShift = %d",RShift , LShift);

}