#include<stdio.h>
int main(){
    float l,b,h,sa;
    printf("Enter the length of Cuboid: ");
    scanf("%f",&l);
    printf("Enter the breadth of Cuboid: ");
    scanf("%f",&b);
    printf("Enter the height of Cuboid: ");
    scanf("%f",&h);
    sa=2*(l*b+b*h+l*h);
    printf("Surface are of Cuboid is %f or in simple numbers %d",sa,(int)(sa+0.5));
    return 0;    
}