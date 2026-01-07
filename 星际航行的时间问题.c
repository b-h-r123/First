#include<stdio.h>

struct DATE
{
	int year,month,day;
};

int isleap(int year)
{
	if((year%4 == 0 && year%100 != 0) || year%400==0)
		return 1;
	else
		return 0;
}

struct DATE count(struct DATE sy,int days)
{
	struct DATE fy =sy;
	int month[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(fy.month<=2)
		month[2] +=isleap(fy.year);
	while(days>month[fy.month]-fy.day)
	{
		days-=month[fy.month]-fy.day;
		fy.day=0;
		fy.month++;
		if(fy.month==13)
		{
			fy.month=1;
			fy.year++;
			while(days>365+isleap(fy.year))
			{
				days-=365+isleap(fy.year);
				fy.year++;
			}
			month[2] = 28 + month[fy.day];
		}
	}
	fy.day+=days;
	return fy;
}

int main()
{
	struct DATE sy;
	struct DATE fy;
	int days;
	printf("请输入初始年份:");
	scanf("%d-%d-%d",&sy.year,&sy.month,&sy.day);
	printf("旅行天数:");
	scanf("%d",&days);
	fy = count(sy,days);
	printf("未来的日期为:%d-%d-%d\n",fy.year,fy.month,fy.day);
	return 0;
}
