#include<stdio.h>
#define N 17

int main()
{
	int a=N,b,x=0;
	printf("猜猜数字，在0-20之间:");
	scanf("%d",&b);
	x++;
	
	while(b!=a && x<5)
	{
    if(b>a)
	printf("数字好像比较大哦，再小一些");
	else
	printf("数字好像比较小哦，再大一些");
	scanf("%d",&b) ;
	x++;
	}
	
	if(b==a)
	{
	printf("恭喜你猜对了,一共用了%d次",x);
	return 0;
	}
	
	printf("提示:数值在10-20之间");
	
	scanf("%d",&b);
	
	while(b!=a)
	 {
		if(b>a)
	    printf("数字好像比较大哦，再小一些");
	    else
	    printf("数字好像比较小哦，再大一些");
	
	scanf("%d",&b) ;
	
	x++;
	}
	
	printf("恭喜你猜对了,一共用了%d次",x);
	
	return 0;
}
