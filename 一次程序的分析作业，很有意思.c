#include<stdio.h>

void numtos(int num, char s[])
{
	static int i=0;
	if(num)
	{
	s[i++] = num%10+'0';
	numtos(num/10,s);
	}
}

int main()
{
	char str[12] = {0};
	int n;
	scanf("%d",&n);
	numtos(n,str);
	puts(str);
	return 0;
}
