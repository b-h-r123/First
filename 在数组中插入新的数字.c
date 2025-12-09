#include<stdio.h>
#define N 11


int mid_bot_top(int a[],int x)
{
	int bot = 0,top = N-2;
	int mid;
	do
	{
	mid = (bot+top)/2;
	if(a[mid] == x)
		return mid;
	else if(a[mid] < x)
		bot = mid+1;
	else
		top = mid-1;
	}while(bot <= top);
	return bot;
}

int main()
{
	int i,x;
	int a[N] = {0};
	printf("原数组为:"); 
	for(i=0;i<N-1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入x:");
	scanf("%d",&x);
	int bot= mid_bot_top(a,x);
	for(i=N-2;i>=bot;i--)
	{
		a[i+1] = a[i];	
	} 
	a[bot] = x;
	printf("新数组为:");
	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	putchar('\n');
	return 0;
}
