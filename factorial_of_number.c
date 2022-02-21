#include<stdio.h>
int find_factorial(int);
int main()
{
 int num, fact;
 printf("\nEnter any integer number:");
 scanf("%d",&num);
 fact =find_factorial(num); //Calling our user defined function
 printf("\nfactorial of %d is: %d",num, fact);
 return 0;
}
int find_factorial(int n)
{
 if(n==0)
 return(1);
 return(n*find_factorial(n-1)); //Function calling itself: recursion
}

