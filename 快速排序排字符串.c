#include<stdio.h>
#include<string.h>
#define N 7 

int position(char *p[N],int x,int y)
{
	int i=x,j=y;
	char* pos=p[x];
	while(i<j)
	{
		while(i<j && strcmp(*(p+j),pos)>=0) j--;
		p[i]=p[j];
		while(i<j && strcmp(*(p+i),pos)<=0)	i++;
		p[j]=p[i];
	}
	p[i]=pos;
	return i;
}

void quick(char *p[N],int x,int r)
{
	int t;
	if(x<r)
	{
		t=position(p,x,r);
		quick(p,x,t-1);
		quick(p,t+1,r);
	}
}

int main()
{
	char nation[N][4]={"CHN","CAN","USA","RUS","AUS","KOR","JPN"};
	char *p[N];
	int i;
	for(i=0;i<N;i++)
	{
		p[i]=nation[i];
	}
	quick(p,0,N-1);
	for(i=0;i<N;i++)
	{
		printf("%s ",*(p+i));
	}
	return 0;
}
