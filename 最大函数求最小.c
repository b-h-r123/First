#include<stdio.h>
int main()
{
	int a,b,c,min;
	printf("请输入三个数:");
	scanf("%d %d %d",&a,&b,&c);
	min=-max(max(-a,-b),-c);
	printf("Min=%d\n",min);
	return 0;
} 

int max(int x,int y)
{
	if(x>=y)
		return x;
	else
		return y;
}
