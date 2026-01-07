#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int y,m,d;
}DATE;

int isleap(int y)
{
	if(y<4&&y>-4)return 0;
	return (y%4==0&&y%100!=0||y%400==0);
}

DATE count(DATE sd,int days)
{
	DATE fd=sd;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(fd.m>2)month[2]+=isleap(fd.y);
	while(days>fd.d)
	{
		days-=fd.d;
		fd.m--;
		fd.d=month[fd.m];
		if(fd.m==0)
		{
			fd.m=12;
			fd.d=month[12];
			fd.y--;
			if(fd.y==0)fd.y=-1;
			while(days>365+isleap(fd.y))
			{
				days-=365+isleap(fd.y);
				fd.y--;
				if(fd.y==0)fd.y=-1;
			}
			month[2]=28+isleap(fd.y);
		}
	}
	fd.d-=days;
	return fd;
}

int main()
{
	DATE sd,fd;
	int days;
	printf("请输入起始日期:");
	scanf("%d-%d-%d",&sd.y ,&sd.m ,&sd.d );
	printf("旅行天数：");
	scanf("%d",&days);
	fd=count(sd,days);
	printf("过去的日期为：%d-%02d-%02d",fd.y ,fd.m ,fd.d );
	return 0;
}
