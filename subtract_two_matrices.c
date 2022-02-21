#include <stdio.h>
#define MAX 100
int main()
{
 int m, n, i, j, first[MAX][MAX], second[MAX][MAX], sum[MAX][MAX];
 printf("Enter the number of rows and columns of matrix\n");
 scanf("%d%d", &m, &n);
 printf("Enter the elements of first matrix\n");
 for (i = 0; i < m;i++)
 {for (j = 0 ; j < n; j++)
 {scanf("%d", &first[i][j]);}}
 printf("Enter the elements of second matrix\n");
 for (i = 0; i < m;i++)
 {for (j = 0 ; j < n; j++)
 {scanf("%d", &second[i][j]);}}
 printf("Sum of entered matrices:-\n");
 for (i = 0; i < m;i++)
{
 for (j = 0 ; j < n; j++)
{
 sum[i][j] = first[i][j] - second[i][j];
 printf("%d\t", sum[i][j]);
 }
 printf("\n");
 }
 return 0;
}
