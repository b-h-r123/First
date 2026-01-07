#include<stdio.h>

int main()
{
	int a,b,c,d;
	printf("请输入三个数:");
	scanf_s("%d %d %d",&a,&b,&c);
	d=max(a,b,c);
    printf("最大的数为:%d\n",d);
	return 0;
}

int max(int x,int y,int z)
{
	int t;
	if(x>y)
		t=x;
	else 
		t=y;
	if(t<z)
		t=z;
	return t;
}
