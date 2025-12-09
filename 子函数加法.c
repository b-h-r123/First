#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d %d",&x,&y);
	z=Add(x,y);
	printf("%d",z);
	return 0;
}

int Add(int a,int b)
{
	int c;
	c = a+b;
	return c;
}
