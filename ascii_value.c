#include<stdio.h>
int main()
{
 char ch;
 printf("\n enter a chatacter :");
 ch = getchar();
 printf("\n the ASCII value of %c is %d", ch,ch);
 printf("\n its previous character is %c with ASCII value %d", ch-1,ch-1);
 printf("\n its next character is %c with ASCII value %d", ch+1,ch+1);
 return 0;
}