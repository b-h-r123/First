#include<stdio.h>
int main()
{
	float score = 0;
	printf("请输入数字:\n");
	scanf_s("%f", &score);
	printf("数值是:%.2f\n",score);
	return 0;
}