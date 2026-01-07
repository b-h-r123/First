#include<stdio.h>
#define N 7

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void transform(int a[N][N])
{
	int i,j;
	int n=N*N;
	int *arr=*a; 
	int temp;
	for(i=0;i<4;i++)
	{
		temp = i;
		for(j=i;j<N*N;j++)
		{
			if(arr[temp]>arr[j])
				temp = j;
		}
		if(temp!=i)
			swap(arr+i,arr+temp);
	}
	for(i=4;i<N-1;i++)
	{
		if(arr[i]>arr[i+1])
			swap(arr+i,arr+i+1);
	}
	swap(arr+n-1,arr+n/2);
	swap(arr+3,arr+n-1);
	swap(arr+2,arr+n-N);
	swap(arr+1,arr+N-1);
	for(i=0;i<n;i++)
	{
		if(i==0 || i==N-1 || i==n/2 || i==n-N || i==n-1)
			printf("%d",arr[i]);
		else
			printf(" ");
		if((i+1)%N == 0)
			printf("\n");
	}
}

int main()
{
	int k=N*N;
	int a[N][N];
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=k--;
		}
	}
	transform(a);
	return 0;
}
