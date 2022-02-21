#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the value of First Number: ");
    scanf("%d",&a);
    printf("Enter the value of Second Number: ");
    scanf("%d",&b);
    printf("First Number : %d \nSecond Number : %d \n", a,b);
    printf("Swapping Values...\n");
    c=a;
    a=b;
    b=c;
    printf("Values After Swapping \nFirst Number: %d \nSecond Number: %d",a,b);
    return 0;
}