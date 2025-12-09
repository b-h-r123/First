#include<stdio.h>
#define M 1

int isperfect(int n)
{
	int i;
	int sum = 1;
	if(n==1)
		return 0;
	for(i=2;i*i<n;i++)
	{
		if(n%i == 0) sum+=i+n/i;
		if(sum>n) return 0;
	}
	if(i*i==n)
		sum += i;
	return sum == n;
}

int main()
{
	int n,i=0,j;
	printf("%d以内的完数:\n",M);
	for(n=2;n<=M;n+=2)
	{
		if(isperfect(n))
		{
			printf("%d\t因子为:1 ",n);
			for(j=2;j<n;j++)
			{
				if(n%j == 0)
					printf("%d ",j);
			}
			i++;
			putchar('\n');
		}
	}
	printf("共%d个\n",i);
	return 0;
}
