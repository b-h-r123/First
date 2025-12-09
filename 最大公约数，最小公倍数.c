#include<stdio.h>

int main()
{
	int a,b;
	printf("请输入两个非负整数:");
	scanf("%d %d",&a,&b);
	printf("最大公约数为:%d\n",gcd(a,b));
	printf("最小公倍数为:%d",gcm(a,b));
	return 0;
}

int gcd(int u,int v)
{
	int r;
	while(v!=0)
	{
		r = u%v;
		u=v;
		v=r; 
	}
	return u;
}

int gcm(int u,int v)
{
	int gcd(int u,int v);
	return((u*v)/gcd(u,v));
}
