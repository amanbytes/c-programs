#include <stdio.h>
#include <stdlib.h>

int adjust( int a[], int cur_pos, int max);
int read_data(int a[], int n);
int heap_sort( int a[], int n);
int print_data(int a[], int n);

void main()
{
	int a[50];
	int n;

	
	printf("\nHow many elements you want ? : ");
	scanf("%d",&n);

	read_data(a,n);

	printf("\nBefore sort:\n");
	print_data(a,n);

	heap_sort(a,n);

	printf("\n\nAfter sort:\n");
	print_data(a,n);

} // main


int read_data(int a[], int n)
{
	int i;
	printf("\nEnter %d values: ",n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	return(0);
} // read datra



int print_data(int a[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%4d",a[i]);
	return(0);

} // print data


int heap_sort( int a[], int n)
{
	int i,t;
	//.... create initial heap tree
	for(i=n/2;i>=1;i--)
		adjust(a,i,n);

	//.... improve initial heap tree
	for(i=n-1;i>=1;i--)
	{
		printf("\n");
		print_data(a,n);
		t = a[i+1];
		a[i+1] = a[1];
		a[1] = t;
		adjust(a,1,i);
	} //for
	return(0);
}//heap_sort

int adjust( int a[], int cur_pos, int max)
{
	int cur_rec, j;

	cur_rec =  a[cur_pos];
	j = cur_pos * 2;

	while( j <=max)
	{
		if( j < max )
		{
			if( a[j] < a[j+1] )
				j++;
		}
		if( a[j] > cur_rec)
		{
			a[j/2] = a[j];
			j = j * 2;
		}
		else
			break;
	} //while
	a[j/2] = cur_rec;
	return(0);
} // adjust