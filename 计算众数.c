#include<stdio.h>

int main()
{
	int most,frep=-1,i;
	int first[33] = {0};
	int a[] = {1,4,2,4,6,32,3,4,1,23,3,3,3,3,23,23,23,23};//18
	int count[33] = {0};
	for(i=0;i<18;i++)
	{
		count[a[i]]++;
		if(first[a[i]]==0)
			first[a[i]] = i+1;
	}
	for(i=0;i<33;i++)
	{
		if(count[i]>frep || count[i]==frep && first[i]<first[most])
		{
			frep = count[i];
			most = i;
		}
	}
	printf("众数为%d,出现次数为%d",most,frep);
	return 0;
}
