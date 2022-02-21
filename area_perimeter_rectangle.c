#include<stdio.h>
int main() {
    float length,breadth,area,perimeter;
    printf("Enter the length of rectangle: ");
    scanf("%f", &length);
    printf("Enter the breadth of rectangle: ");
    scanf("%f", &breadth);
    area=length*breadth;
    perimeter=2*(length+breadth);
    printf("The area of the rectangle is %f or in simple numbers, it is %d. \n",area,(int)(area+0.5));
    printf("The perimeter of the rectangle is %f or in simple numbers, it is %d. \n",perimeter,(int)(perimeter+0.5));
    return 0;
}