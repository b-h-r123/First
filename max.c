#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,max=0;
	printf("请输入三个数:");
	scanf("%d %d %d",&a,&b,&c);
	if (a>b) 
	   max=a;
	else 
	   max=b;
	if (max<c) 
	   max=c;
	printf("最大的数:%d\n",max);
	return 0;
}
