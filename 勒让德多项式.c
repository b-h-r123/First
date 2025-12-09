#include<stdio.h>

double Prd(int n,double x)
{
	if(n==0)
		return 1;
	else if(n==1)
		return x;
	else if(n>1)
		return ((2*n-1)*x*Prd(n-1,x)-(n-1)*Prd(n-2,x))/n;
}

int main()
{
	int n;
	double x;
	printf("«Î ‰»În,x:");
	scanf("%d %lf",&n,&x);
	double z = Prd(n,x);
	printf("P(%d,%lf)=%lf\n ",n,x,z);
	return 0; 
}
