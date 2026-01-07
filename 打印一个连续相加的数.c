#include<stdio.h>

int main()
{
	int a,n,i,sum=0;
	printf("Imput a and n:");
	scanf("%d %d",&a,&n);
	int j=a;
	for(i=1;i<n;i++)
	{
		printf("%d+",a);
		sum+=a;
		a=j+a*10;
	}
	sum += a;
	printf("%d=%d\n",a,sum);
	return 0;
}
