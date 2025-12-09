#include<stdio.h>
int main() 
{
	int y,m,d;
	printf("请输入年份，月份:");
	scanf("%d %d",&y,&m);
	d=monthday(y,m);
	printf("第%d年的第%d月一共有%d天",y,m,d);
	return 0;
}

int runyear(int y)
{
	if((y%4 == 0 && y%100 != 0) || y%400 == 0)
		return 1;
	else 
		return 0;
}

int monthday(int y,int m)
{
	int days [] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int d = days[m];
	if(runyear(y) == 1 && m == 2)
		d++;
	return d;
}
