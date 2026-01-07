#include<stdio.h>
int main()
{
	int a=0;
	printf("请输入一个数:");
	scanf("%d",&a);
	while(a)
	{
		printf("%d",a%10);
		a /= 10;
	 } 
	return 0;
}
