#include<stdio.h>

void s(int a[],int n)
{
	int *p=a+n-1;
	int temp=*p;
	for( ;p>a;p--)
	{
		*p = *(p-1);
	}
	*a = temp;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	int m;
	printf("原数组为:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n请输入m:");
	scanf("%d",&m);
	while(m>n)
		m%=n;
	for(i=0;i<m;i++)
		s(a,n);
	printf("结果为:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
