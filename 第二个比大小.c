#include<stdio.h>

int main()
{
	int max2;
	int a,b,c;
	printf("请输入两个数:");
	scanf("%d",&a);
	scanf("%d",&b);
	c=max(a,b);
	printf("最大值为:%d",c);
	return 0;
}

int max2(int x,int y)
{
	int z;
	if(x>y)
		z=x;
	else 
		z=y;
	return z;
}
