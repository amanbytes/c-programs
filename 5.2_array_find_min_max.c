#include<stdio.h>
#define MAX 100
int main(){
    int arr[MAX],i,max,min,size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements in the array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    // assume first element as maximum and minium
    max=arr[0];
    min=arr[0];
    // finding the maximum and minimum in all array elements
    for(i=0;i<size;i++)
    {
        // if current element is greater than max
        if(arr[i]>max)
        {
            max=arr[i];
        }
        // if current element is smaller than min
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    // print minimum and maximum element
    printf("\nMaximum Element = %d", max);
    printf("\nMinimum Element = %d", min);
    return 0;
}