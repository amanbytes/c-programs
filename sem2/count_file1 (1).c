#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *file;
char path[100],ch;
int words,lines,chars;
words=chars=lines=0;
printf("\nEnter the path of file:");
scanf("%s",path);
file=fopen(path,"r");
while((ch=fgetc(file)) !=EOF)
{
chars++;
if(ch=='\n'|| ch=='\0')
lines++;
if(ch==' ' || ch=='\t' || ch=='\n' || ch=='\0')
words++;
}
if (chars>0)
words++;
printf("\nTotal\nChracters:%d\nWords:%d\nLines:%d\n",chars,words,lines);
fclose(file);
}
