#include<stdio.h>
int main()
{
	double i,bonus=0;
	int c;
	printf("请输入利润:");
	scanf("%lf",&i);
	c=i/100000;
	if(c>10)
		c=10;
	switch(c)
	{
		case 10:bonus += (i-1000000)*(0.01);
				i=1000000;
		case 9:
		case 8:
		case 6:bonus += (i-600000)*(0.015);
				i=600000;
		case 5:
		case 4:bonus += (i-400000)*(0.03);
				i=400000;
		case 3:
		case 2:bonus += (i-200000)*(0.05);
				i=200000;
		case 1:bonus += (i-100000)*(0.075);
				i=100000;
		case 0:bonus += i*(0.1); 
	}
	printf("奖金为:%.2lf\n",bonus);
	return 0;
}
