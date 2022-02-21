#include <stdio.h>
int main()
{
 int num, temp, digit, sum = 0;
 printf("Enter the number \n");
 scanf("%d", &num);
 temp = num;
 while (num > 0)
 {
 digit = num % 10;
 sum = sum + digit;
 num /= 10;
 }
 printf("Given number = %d\n", temp);
 printf("Sum of the digits %d = %d\n", temp, sum);
}