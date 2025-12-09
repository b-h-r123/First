#include<stdio.h>
#define N 7

void bubble(int a[])
{
	int i,j;
	for(i=1;i<N;i++)
	{
		for(j=0;j<N-i;j++)
		{
			int null;
			if(a[j]>a[j+1])
			{
				null = a[j];
				a[j] = a[j+1];
				a[j+1] = null;
			}
		}	
	}	
}

int main()
{
	int a[N] = {0};
	int i;
	printf("请输入%d个数:",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a);
	printf("排序后的为:");
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	} 
	putchar('\n');
	return 0;
}
