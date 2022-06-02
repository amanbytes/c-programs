#include<stdio.h>
#include<stdlib.h>
int main()
{
int *p,n,i,max,sum,avg;
printf("Enter the size of array:");
scanf("%d",&n);
p=malloc(n*sizeof(int));
printf("\nEnter elements: ");
for(i=0;i<n;i++)
scanf("%d",p+i);
max=*p;
sum=0;
for(i=0;i<n;i++)
{
sum+=*(p+i);
if(*(p+i)>max)
max=*p+i;
}
printf("%d is Largest",max);
printf("\nSum: %d",sum);
printf("\nAverage: %d",sum/n);
}
