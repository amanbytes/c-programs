#include<stdio.h>
int main()
{
int a,b,*p1,*p2,temp;
p1=&a;
p2=&b;
printf("\nEnter the first number: ");
scanf("%d",&a);
printf("\nEnter the second number: ");
scanf("%d",&b);
printf("\nNumbers before swapping\na:%d\nb:%d",a,b);
temp=*p1;
*p1=*p2;
*p2=temp;
printf("\nNumbers after swapping\na:%d\nb:%d",a,b);
}
