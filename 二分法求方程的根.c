#include<stdio.h>
#define E 1e-7
#include<math.h>

double f(double x)
{
	return (2*x*x*x-4*x*x+3*x-6);
}

int main()
{
	double x=1.5,y=3,z;
	while(fabs(x-y)>E)
	{
		z=(x+y)/2;
		if(f(x)*f(z) < 0)
			y=z;
		else
			x=z;
	}
	printf("root=%.6lf",x);
	return 0;
}
