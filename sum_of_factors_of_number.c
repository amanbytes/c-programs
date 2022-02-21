#include <stdio.h>
int main()
{
 int number, i, total = 0;
 printf("Enter a number: ");
 scanf("%d", &number);
 printf("The factors of %d are:\n", number);
 for (i = 1; i <= number; i++)
 {
 if (number % i == 0)
 {
 printf("%d\n", i);
 total+=i;
 }
 }
 printf("The sum of all the factors of %d is %d\n", number, total);
return(0);
}
