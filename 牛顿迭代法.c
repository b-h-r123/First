#include<stdio.h>
#include<math.h>
#define E 1e-7

double f(double x)
{
	return (2*x*x*x-4*x*x+3*x-6);
}

double f1(double x)
{
	return (6*x*x-8*x+3);
}

int main()
{
	double f(double x);
	double f1(double x);
	double x=1.5,y;
	while(fabs(x-y)>E)
	{
		y=x;
		x=x-f(x)/f1(x);
	}
	printf("root=%.6lf",x); 
	return 0;
}
