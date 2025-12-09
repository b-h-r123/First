#include<stdio.h>
#define M 7
#define N 5

void Print(float (*p)[N+1])
{
	int i,j;
	printf("\n原成绩如下:\n");
	for(i=0;i<M;i++)
	{
		printf("%d\t",i+1);
		for(j=1;j<=N;j++)
		{
			printf("%.1f ",*(*(p+i)+j));
		}
		printf("%   .2f",**(p+i));
		putchar('\n');
	}
	putchar('\n');
} 

float ave_sco(float (*p)[N+1],int n)
{
	float sum=0;
	int i;
	for(i=0;i<M;i++)
	{
		//sum+=*(*(p+i)+n);
		sum+=p[i][n];
	}
	return sum/M;
}

float *fail(float *p)
{
	int j,count=0;
	for(j=1;j<=N;j++)
	{
		if(*(p+j)<60)
			count++;
	}
	if(count>=2)
		return p;
	else
		return NULL;
}

float* good(float (*p)[N+1])
{
	int i;
	if(**p>=90)
		return *p;
	for(i=1;i<=N;i++)
	{
		if(*(*p+i)<85)
			return NULL;	
	}
	return *p;	
} 

int main()
{
	float score[M][N+1] = { 0 };
	int i, j;
	int n=1;
	for (i = 0; i < M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%f", &score[i][j]);
		}
	}
	float stu_sum=0;
	for(i=0;i<M;i++)
	{
		stu_sum=0; 
		for(j=1;j<=N;j++)
		{
			stu_sum+=score[i][j];
		}
		score[i][0]=(stu_sum)/N;
		stu_sum=0;
	}
	Print(score); 
	float avescore=ave_sco(score,n);
	printf("第%d门课的平均成绩为:%.2f\n",n,avescore);
	putchar('\n');
	int flag=0;
	float* fai;
	for(i=0;i<M;i++)
	{
		fai=fail(*(score+i));
		if(fai!=NULL)
		{
			if(flag==0)
				printf("两门（含）以上不及格的学生信息\n");
			flag=1;
			printf("%d\t",i+1);
			for(j=1;j<=N;j++)
			{
				printf("%.1f ",*(*(score+i)+j));
			}
			printf("%   .2f",**(score+i));
			putchar('\n');
		}
	}
	putchar('\n'); 
	float *goo;
	flag=0;
	for(i=0;i<M;i++)
	{
		goo=good(score+i);
		if(goo!=NULL)
		{
			if(flag==0)
				printf("总体上成绩优秀的学生信息\n");
			flag=1;
			printf("%d\t",i+1);
			for(j=1;j<=N;j++)
			{
				printf("%.1f ",*(*(score+i)+j));
			}
			printf("   %.2f",**(score+i));
			putchar('\n');
		}
	}
	return 0;
}
