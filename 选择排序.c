#include<stdio.h>
#define N 6

void swap(int a[],int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void select(int a[])
{
	int i,j,k;
	for(i=0;i<N-1;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
		{
			if(a[k]<a[j])
				k=j;
		}
		if(k!=i)
			swap(a,k,i);
	}
}

int main()
{
	int a[N] = {0};
	int i;
	printf("请输入10个数:");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	select(a);
	printf("排列后的数组为:");
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
