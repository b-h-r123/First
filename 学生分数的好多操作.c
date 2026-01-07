#include<stdio.h>
#define M 3
#define N 5

int h_s,h_c;
void process1(float score[M][N],float ave_s[M]);
void process2(float score[M][N],float ave_c[N]);
void highest(float score[M][N]);
double var(float ave_s[M]);

int main()
{
	float score[M][N] = {{70,70,70,70,99.5},{70,70,70,70,70},{70,70,70,70,70}};
	float ave_s[M],ave_c[N];
	int i,j;
	process1(score,ave_s);
	process2(score,ave_c);
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%.1lf ",score[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	for(i=0;i<M;i++)
	{
		printf("第%d个学生的平均分为%.2lf\n",i+1,ave_s[i]);
	}
	putchar('\n');
	for(i=0;i<N;i++)
	{
		printf("第%d门课程平均分为%.2lf\n",i+1,ave_c[i]);
	}
	putchar('\n');
	highest(score);
	putchar('\n');
	double v=var(ave_s);
	printf("学生平均分方差:%.3lf\n",v);
	return 0;
}

void process1(float score[M][N],float ave_s[M])
{
    int i,j;
    for(i=0;i<M;i++)  
    {
        float sum=0; 
        for(j=0;j<N;j++) 
        {
            sum+=score[i][j];
        }
        ave_s[i] = sum/N;
    }
}

void process2(float score[M][N],float ave_c[N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        float sum=0; 
        for(j=0;j<M;j++)
        {
            sum+=score[j][i]; 
        }
        ave_c[i] = sum/M;
    }
}


void highest(float score[M][N])
{
    float max = score[0][0];
    int i, j; 
    h_s = 0;  
    h_c = 0; 
    
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(score[i][j] > max)
            {
                h_s = i;
                h_c = j;
                max = score[i][j]; 
            }
        }
    }
    printf("最高成绩为%.2lf,是第%d位学生的第%d门课\n", max, h_s+1, h_c+1);
}

double var(float ave_s[M])
{
	double sum1=0,sum2=0,v;
	int i;
	for(i=0;i<M;i++)
	{
		sum1+=(ave_s[i] * ave_s[i]);
		sum2+=ave_s[i];
	}
	v = sum1/M - (sum2/M)*(sum2/M);
	return v;
}
