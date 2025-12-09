#include<stdio.h>
#define N 6

int position(int a[],int z,int y)
{
	int i=z,j=y,pos=a[z];
	while(i<j)
	{
		while(i<j && a[j]>=pos) j--;
		a[i]=a[j];
		while(i<j && a[i]<=pos) i++;
		a[j]=a[i];
	}
	a[i]=pos;
	return i;
}

void quick(int a[],int z,int r)
{
	int p;
	if(z<r)
	{
		p=position(a,z,r);
		quick(a,z,p-1);
		quick(a,p+1,r);
	}
}

int main()
{
	int i;
	int a[N];
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	quick(a,0,N-1);
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
	return 0;
}
