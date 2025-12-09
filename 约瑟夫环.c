#include<stdio.h>

void ring(int people,int spice,int a[])
{
	int pre=people-1,now=0,out=0,count=0;
	while(out<people)
	{
		count++;
		if(count==spice)
		{
			printf("%d ",now+1);
			a[pre]=a[now];
			out++;
			if(out%10==0)
				putchar('\n');
			count=0; 
		}
		else
			pre=now;
		now=a[now];
	}
}

int main()
{
	int people,spice,i;
	int a[100];
	printf("请输入总人数:");
	scanf("%d",&people);
	printf("\n请输入倍数:");
	scanf("%d",&spice); 
	putchar('\n');
	for(i=0;i<people;i++)
	{
		a[i]=(i+1)%people;
	} 
	ring(people,spice,a);
	return 0;
}
