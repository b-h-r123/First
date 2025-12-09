#include<stdio.h>
int main()
{
	int year;
	printf("ÇëÊäÈëÄê·İ:");
	scanf("%d",&year);
	int t = runyear(year);
	if(t==1)
		printf("Yes");
	else
		printf("No");
	return 0;
}

int runyear(int a)
{
	if((a%4==0 && a%100!=0) || a%400==0)
		return 1;
	else 
		return 0;
}
