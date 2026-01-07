#include<stdio.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubble(int *a,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
				swap(a+j,a+j+1);
		}
	}
}

int main()
{
	char str[100] = {0};
	int i=0,n=0;
	char ch;
	while((ch=getchar())!='\n')
	{
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	int a[10] = {0};
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]>='0' && str[i]<='9')
		{
			a[n]=str[i]-'0';
			n++;
		}
		i++;
	}
	bubble(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
