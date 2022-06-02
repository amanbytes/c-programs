#include<stdio.h>
#include<string.h>
struct employee
{
int id;
char name[20];
int salary;
};

int main()
{
int i=0,MAX=25;
printf("\nEnter the number of employees: ");
scanf("%d",&MAX);
struct employee e[MAX];
for(i=0;i<MAX;i++)
{
printf("Enter emp id: ");
scanf("%d",&e[i].id);
printf("Enter name: ");
scanf("%s",e[i].name);
printf("Enter salary: ");
scanf("%d",&e[i].salary);
}
for(i=0;i<MAX;i++)
printf("\nId:%d,\nName:%s\nSalary:%d\n",e[i].id,e[i].name,e[i].salary);
printf("Salary greater than 10");
for(i=0;i<MAX;i++)
{
if(e[i].salary>10)
printf("\nId:%d,\nName:%s\nSalary:%d\n",e[i].id,e[i].name,e[i].salary);
}
printf("Search someone by name");
char name[20];
printf("Enter the name to search");
scanf("%s",name);
for(i=0;i<MAX;i++)
{
if(strcmp(e[i].name,name)==0)
printf("\nId:%d,\nName:%s\nSalary:%d\n",e[i].id,e[i].name,e[i].salary);
}
}
