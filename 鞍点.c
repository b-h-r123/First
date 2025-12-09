#include<stdio.h>
#define N 3
#define M 4

int hang(int a[][M],int l); 
int lie(int a[][M],int h);

int main()
{
	//int a[N][M] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int a[N][M] = {{1,2,3,8},{5,6,7,4},{9,10,11,12}};
	int i,j,t=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%d ",a[i][j]);
		}
		putchar('\n');
	}
	for(i=0;i<M;i++)
	{
		int h = lie(a,i);
		int l = hang(a,h);
		if(l == i)
		{
			printf("鞍点是%d，在第%d行第%d列\n",a[h][l],h+1,l+1);
			t = 1;
		} 
	}
	if(!t)
		printf("无鞍点\n");
	return 0;
}

int hang(int a[][M],int h)
{
	int l=0,i,max = a[h][0] ;
	for(i=1;i<M;i++)
	{
		if(max<a[h][i])
		{
			max = a[h][i];
			l=i;
		}
	}
	return l;
}

int lie(int a[][M],int l)
{
	int h=0,i,min = a[0][l];
	for(i=1;i<N;i++)
	{
		if(min>a[i][l])
		{
			min = a[i][l];
			h=i;
		}
	}
	return h;
}


