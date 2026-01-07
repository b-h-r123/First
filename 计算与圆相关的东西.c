#include<stdio.h>
#define PI 3.1415927
int main()
{
	double r,h;
	double c,s,ss,vq,vz;
	printf("请输入半径与高");
	scanf("%lf %lf",&r,&h);
	c=2*PI*r;
	s=PI*(r*r);
	ss=4*PI*(r*r);
	vq=(4.0/3)*PI*(r*r*r);
	vz=PI*(r*r)*h; 
	printf("周长为%.3lf\n",c);
	printf("面积为%.3lf\n",s);
	printf("圆球表面积为%.3lf\n",ss);
	printf("圆球的体积为%.3lf\n",vq);
	printf("圆柱的体积为%.3lf\n",vz);
	return 0;
}
