#include<stdio.h>
#define N 1

int a[N+1]; 

int main()
{
	int i,j;
	int count = N>=2?1:0;
	for(j = 4; j <= N; j += 2)
        a[j] = 1;
	for(i=3;i*i<=N;i+=2)
	{
		if(a[i]) continue;
		for(j=i*i;j<=N;j+=2*i)
			if(!a[j]) a[j]=1;
	}
	for(i=3;i<=N;i++)
	{
		if(!a[i]) count++;
	}
	printf("%d(含)内的素数一共有%d个",N,count);
	return 0;
}
