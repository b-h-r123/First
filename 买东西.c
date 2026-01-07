#include<stdio.h>
int main()
{
	int a;
	printf("电子产品请输入1，家居产品请输入2\n");
	scanf("%d",&a);
	if(a==1)
	{
		int x;
		printf("请输入价格:");
		scanf("%d",&x);
		if(x<500)
			printf("电子产品价格低，无法享受优惠");
		else if(x>=500 && x<1000)
			printf("电子产品可享受5%%优惠");
		else
			printf("享受10%%");
			return 0;
	}
	if(a==2)
	{
		int x;
		printf("请输入价格:");
		scanf("%d",&x);
		if(x<500)
			printf("产品价格低，无法享受优惠");
		else if(x>=500 && x<1000)
			printf("产品可享受5%%优惠");
		else
			printf("享受10%%");
			return 0;
		return 0;
	}
	return 0;
}
