#include<stdio.h>
int main()
{
	int x,y,bit=0,weight=0;
	printf("请输入一个非负整数:");
	scanf("%d",&x);
	y=x;
	printf("逆序为:");
	do
	{
		printf("%d",x%10);
		x/=10;
		bit++;
		if(weight == 0)
			weight =1;
		else weight *= 10;
		
	}while(x>0);
	printf("\n他是一个%d位数\n",bit);
	printf("各个数字为:");
	while(y>=0)
	{
		printf("%d ",y/weight);
		y=y%weight;
		weight/=10;
	}
	return 0;
}
