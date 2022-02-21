#include <stdio.h>
#define MAX 100
int main()
{
 int arr[MAX]; int size, i;
 printf("Enter size of the array: ");
 scanf("%d", &size);
 /* Input array elements */
 printf("Enter elements in array: ");
 for(i=0; i<size; i++)
 {
 scanf("%d", &arr[i]);
 }
 // Print array in reversed order
 printf("\nArray in reverse order: ");
 for(i = size-1; i>=0; i--)
 {
 printf("%d\t", arr[i]);
 }
 return 0;
}
