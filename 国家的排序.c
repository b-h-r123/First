#include<stdio.h>
#include<string.h>
#define N 10

void insert(char a[][N],int n)
{
	int i,j;
	char temp[N];
	for(i=1;i<n;i++)
	{
		strcpy(temp,a[i]);
		for(j=i-1;j>=0 && strcmp(temp,a[j]) < 0;j--)
		{
			strcpy(a[j+1],a[j]);
		}
		strcpy(a[j+1],temp);
	}
}

int main()
{
	int i;
	char nation[][N] = {"CHINA","USA","RUSSIA","UK","FRANCE"};
	insert(nation,5);
	printf("ÅÅÐò½á¹ûÎª:\n");
	for(i=0;i<5;i++)
	{
		printf("%s\n",nation[i]);
	}
	return 0;
}
