#include<stdio.h>
int main()
{
	double i,bonus=0;
	printf("请输入利润:");
	scanf("%lf",&i);
	if(i>1000000)
	{
		bonus += (i-1000000)*(0.01);
		i=1000000; 
	}
	if(i>600000)
	{
		bonus += (i-600000)*(0.015);
		i=600000;
	}
	if(i>400000)
	{
		bonus += (i-400000)*(0.03);
		i=400000;
	}
	if(i>200000)
	{
		bonus += (i-200000)*(0.05);
		i=200000;
	}
	if(i>100000)
	{
		bonus += (i-100000)*(0.075);
		i=100000;
	}
	if(i<=100000)
		bonus += i*(0.1);
	printf("奖金为:%.2lf\n",bonus);
	return 0;
}
