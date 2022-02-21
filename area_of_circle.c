#include<stdio.h>
#define PI 3.14
int main()
{
 float radius, area=0,cirf=0;
 printf("\n Enter radius of circle: ");
 scanf("%f", &radius);
 area = PI * radius * radius;
 cirf = 2 * PI * radius;
 printf("\n Area of circle : %.2f ", area);
 printf("\n Circumference : %.2f ", cirf);
 return 0;
}