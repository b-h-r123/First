#include<stdio.h>

int isleap(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return 1;
	else
		return 0;
} 

int allday(int fy,int fm,int fd,int sy)
{
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30}; 
	int days=(fy-sy)*365;
	int i;
	for(i=sy;i<fy;i++)
	{
			if(isleap(i))
				days++;
	}
	for(i=0;i<fm;i++)
	{
		days+=month[i];
	}
	if(fm>2)
		days+=isleap(fy);
	return (days+fd);
}

int main()
{
	int sy,sm,sd,fy,fm,fd;
	printf("请输入起始日期:");
	scanf("%d-%d-%d",&sy,&sm,&sd);
	printf("请输入终止日期:");
	scanf("%d-%d-%d",&fy,&fm,&fd);
	int day = allday(fy,fm,fd,sy)-allday(sy,sm,sd,sy);
	printf("dis=%d\n",day);
	return 0;
}
