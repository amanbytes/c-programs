#include<stdio.h>
int main(){
    int mat[10][10], i,j, row,col;
    printf("\nEnter the order of the matrix: ");
    scanf("%dx%d", &row, &col);
    printf("\nEnter the elements of the matrix: \n\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n\nThe elements in the matrix are: \n\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}