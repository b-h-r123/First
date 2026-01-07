#include<stdio.h>
#include<string.h>

int num(char a[],int n,int number[])
{
	int count=0,i,j,c=0;
	char *s=a;
	int temp=0;
	for(i=0;i<=n;i++)
	{
		if(*(s+i)>='0' && *(s+i)<='9')
		{
			temp = 1;			
		}
		if((*(s+i) < '0' || *(s+i) >'9') && temp==1)
		{
			count++;
			temp=0; 
		}
		if(*(s+i) == '\0' && temp==1)
			count++; 
	}
	i=0;
	j=0;
	while(i<=n)
	{
		while(*(s+i)<'0' || *(s+i)>'9')
		{
			i++;
		}
        if(i<=n && *(s+i)>='0' && *(s+i)<='9')
        {
            int sum=0;
            while(i<=n && *(s+i)>='0' && *(s+i)<='9')
            {
                sum=sum*10+(*(s+i)-'0');
                i++;
            }
            number[j]=sum;
            j++;
        }
	}
	return count;
}

int main()
{
	char a[] = "012A123x456 17960? 302tab0";
	int b=strlen(a);
	int number[13];
	int c = num(a,b,number);
	int i;
	printf("%d\n",c);
	for(i=0;i<c;i++)
	{
		printf("%d ",number[i]);
	}
	return 0;
}
