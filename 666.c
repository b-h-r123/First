#include<stdio.h>
int main() {
	int a, b,c;
	printf("请输入两个数字:");
	scanf_s("%d %d", &a, &b);
	c = max(a, b);
	printf("最大值为%d\n", c);
	return 0;
}
int max(int x, int y) {
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return z;
}
