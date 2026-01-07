#include<stdio.h>

struct DATE
{
	int year,month,day;
};

int isleap(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return 1;
	else
		return 0;
}

struct DATE count(struct DATE sd,int days)
{
	struct DATE fd =sd;
	int month[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(fd.month>2)
		month[2] +=isleap(fd.year);
	while(days>=fd.day)
	{
		days-=fd.day;
		fd.month--;
		fd.day=month[fd.month];
		if(fd.month==0)
		{
			fd.month=12;
			fd.day=month[fd.month];
			fd.year--;
			while(days>365+isleap(fd.year))
			{
				days-=365+isleap(fd.year);
				fd.year--; 
			}
			if(fd.year==0)
				fd.year--;
			month[2] = 28 + isleap(fd.year);
		}
	}
	fd.day-=days;
	return fd;
}

int main()
{
	struct DATE sd;
	struct DATE fd;
	int days;
	printf("请输入年份:");
	scanf("%d-%d-%d",&sd.year,&sd.month,&sd.day);
	printf("旅行天数:");
	scanf("%d",&days);
	fd=count(sd,days);
	printf("过去日期为:%d-%02d-%02d",fd.year,fd.month,fd.day); 
	return 0;
}
