#include<stdio.h>

void rev(int a[],int l,int r)
{
	int *p=a+l,*q=a+r;
	for( ;p<q;p++,q--)
	{
		int temp = *p;
		*p = *q;
		*q = temp;
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int i,m;
	int n = sizeof(a) / sizeof(a[0]); 
	printf("原数组为:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n请输入m:");
	scanf("%d",&m);
	while(m>n)
		m%=n;
	rev(a,0,n-m-1);
	rev(a,n-m,n-1);
	rev(a,0,n-1);
	printf("结果为:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return 0;
} 
