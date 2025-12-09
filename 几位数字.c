#include<stdio.h>
int main()
{
	int a=0,n=0;
	printf("请输入一个数:");
	scanf("%d",&a);
	do
	{
		a/=10;
		n++;
	}while(a);
	printf("有%d位",n);
	return 0;
}
