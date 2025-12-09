#include<stdio.h>
int main(){
	int a;
	printf("请输入一个年份:");
	scanf("%d",&a);
	if(a%4==0)
	printf("这一年为闰年");
	else
	printf("这一年不是闰年");
	return 0;
}
