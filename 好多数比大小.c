#include<stdio.h>
#define N 6

int main()
{
	int a,b,n=1;
	printf("请输入6个数:");
	scanf("%d",&a);
	do
	{
		scanf("%d",&b);
		if(b>a) a=b;
		n++;
	}while(n<N);
	printf("最大值是:%d",a);
	return 0;
}
