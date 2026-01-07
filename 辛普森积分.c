#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1e7

void Print()
{
	printf("1.sin(x) 2.cos(x) 3.exp(x)+1 0.exit");
}

double f1(double x)
{
	return sin(x);
}

double f2(double x)
{
	return cos(x);
}

double f3(double x)
{
	return exp(x) + 1;
}

double integral(double a, double b, double (*p)(double))
{
	double sum = 0;
	double h = (b - a) / N;
	sum += (*p)(a);
	int i;
	for (i=1;i<N;i++)
	{
		sum += ((*p)(a + (i + 1) * h));
	}
	//sum += ((*p)(a) + (*p)(b))/2;
	//int i;
	//for(i=1;i<N;i++)
	//{
	//	sum += ((*p)(a+i*h));
	//}
	sum = sum * h;
	return sum;
}

int main()
{
	int n;
	while (1)
	{
		Print();
		putchar('\n');
		printf("请选择一个函数:");
		scanf("%d", &n);
		double (*p)(double)=NULL;
		switch (n)
		{
		case 1: p = f1; break;
		case 2: p = f2; break;
		case 3: p = f3; break;
		case 0: exit(0);
		}
		double a, b;
		printf("请输入下界和上界:");
		scanf("%lf %lf", &a, &b);
		double res = integral(a, b, p);
		printf("结果为:%.6lf\n", res);
		putchar('\n');
	}
	return 0;
}
