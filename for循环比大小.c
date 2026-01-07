#include<stdio.h>
#define N 5

int main()
{
	int a,n,b;
	printf("请输入五个数字:");
	scanf("%d",&a);
	for(n=1;n<N;n++)
	{
		scanf("%d",&b);
		if(a>b)
			a=b;
		else ;
	}
	printf("最大的数为%d",b);
	return 0;
}
