#include<stdio.h>
#include<string.h>
int main()
{
char ch[100],dh[100];
printf("\nEnter the first string:");
fgets(ch,100,stdin);
printf("\nEnter the second  string:");
fgets(dh,100,stdin);
int cmp;
cmp=strcmp(ch,dh);
if(cmp==0)
printf("Both strings are same");
if(cmp<0)
printf("String 1 is greater than String 2");
if(cmp>0)
printf("String 2 is greater than String 1");
printf("\nString 1:%s\nString 2:%s",ch,dh);
strcpy(ch,dh);
printf("After copying string 1 to string 2");
printf("\nString 1:%s\nString 2:%s",ch,dh);

}
