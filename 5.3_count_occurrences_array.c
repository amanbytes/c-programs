#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],n,i,num,count;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
    {
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nEnter number to find occurrence:");
    scanf("%d",&num);
    count=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        count++;
    }
    printf("\nOccurence of %d is : %d",num,count);
    return 0;
}