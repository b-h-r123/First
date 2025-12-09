#include<stdio.h>

int main()
{
	int i;
	for(i=1;i<10;i++)
	{
		int j;
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%d ",j,i,j*i);
		}
		printf("\n");
	}
	return 0;
}
