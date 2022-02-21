#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],size,i,toSearch,found;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    // input elements of array
    printf("\nEnter elements in array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d",&toSearch);
    found=0;
    for(i=0;i<size;i++)
    {
        if(arr[i]==toSearch)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("\n%d is found at positon %d",toSearch,i+1);
    }
    else
    {
        
        printf("\n%d is not found in the array",toSearch);
    }
    return 0;
}