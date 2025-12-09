#include<stdio.h>

int main()
{
	int x,y;
	printf("请输入时间和过去的值:");
	scanf("%d %d",&x,&y);
		x = (x/100 + (x%100 + y)/60)*100 + (x%100 + y)%60;
	printf("最新的时间为:%d",x);
	return 0;
}
