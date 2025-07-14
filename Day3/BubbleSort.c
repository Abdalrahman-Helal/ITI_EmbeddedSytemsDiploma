#include <stdio.h>

void BubbleSort(int num[] , int ArrSize);
void BinarySearch(int num[], int ArrSize, int Search);


void main(void)
{
    int Number;
    int arr[10]={5,3,8,4,9,7,3,1,12,10};

    int size =sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr,size);

    printf("Please Enter Number to Search");
    scanf("%d",&Number);
    BinarySearch(arr , size , Number);
}

void BubbleSort(int num[] , int ArrSize)
{
    printf("Bubble Sorting\n");

    for(int i=0; i<ArrSize; i++)
    {
        for(int j=0; j<ArrSize-i-1;j++)
        {
           if(num[j]>num[j+1])
           {
                int temp;
                temp = num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
           }
        }
    }

    for(int k=0; k<ArrSize; k++)
    {
        printf("%d\n",num[k]);
    }
}

void BinarySearch(int num[], int ArrSize, int Search)
{
    int Flag = 0;
    // if(Search = num[0])
    // {
    //     Flag = 1;
    // }
    int Start=0 , Mid , End=ArrSize-1;
   
    
    // if(flag != 1)
    while(Start<=End)
    {
         Mid = (Start+End)/2;
        if(Search == num[Mid])
        {
            Flag = 1;
            printf("The Number is found ");
            break;
        }
        else if(Search < num[Mid])
        {
            End = Mid-1;
            
        }
        else if(Search > num[Mid])
        {
            Start = Mid+1;
            
        }
    }

    if(Flag == 0)
    {
        printf("Number not found");
    }
   
}