#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#define Min 1000
#define Max 3000

struct data
{
	char name[20];
	int sale[13];
}; 

void swap(struct data *p[],int i,int j)
{
	struct data *temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void creat_data(struct data pp[])
{
	int i,j,sum;
	srand(time(NULL));
	for(i=0;i<4;i++)
	{
		sum=0;
		for(j=1;j<13;j++)
		{
			(pp+i)->sale[j] = (Min)+rand()%(Max-Min+1);
			sum+=(pp+i)->sale[j];
		}
		pp[i].sale[0] = sum;
	}
}

void month_sort(struct data *p[], int n, int m)
{
    int i, j;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(p[j]->sale[m] < p[j + 1]->sale[m])
                swap(p, j, j + 1);    
        }
    } 
}

void Print_m(struct data *p[],int n,int m)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-5d%-5s%5d\n",i+1,(*(p+i))->name,(*(p+i))->sale[m]);
	}
}

int main()
{
	int n=4;
    struct data pp[4] = {
        {"华为", {0}},
        {"vivo", {0}},
        {"oppo", {0}},
        {"mi", {0}}
    };
	creat_data(pp);
	int i;
	struct data *p[4];
	for(i=0;i<4;i++)
	{
		p[i] = &pp[i];
	}
	int m=1;
	int t=0;
	for(m=0;m<n;m++)
	{
		printf("%-5d%-5s",m+1,(*(p+m))->name);
		for(t=0;t<13;t++)
		{
			printf("%d ",(*(p+m))->sale[t]);
		}
		putchar('\n');
	}
	putchar('\n'); 
	while(1)
	{
		printf("请输入月份(-1退出):");
		scanf("%d",&m);
		if(m==-1)
			break;
		month_sort(p,n,m);
		Print_m(p,n,m);
		putchar('\n'); 
	}
	return 0;
}
