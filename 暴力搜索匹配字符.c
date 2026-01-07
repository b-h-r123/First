#include<stdio.h>
#include<string.h>

int BF(char st[],char sp[])
{
	int i,j;
	int len1 = strlen(st);
	int len2 = strlen(sp);
	for(i=0;i<=len1 - len2;i++)
	{
		for(j=0;j<len2 && st[i+j]==sp[j];j++)
			;
		if(j == len2)
			return i;
	}
	return -1;
}

int main()
{
	char st[] = "ababbab";
	char sp[100];
	printf("目标串为%s\n请输入模式串",st);
	scanf("%s",sp);
	int a = BF(st,sp);
	if(a != -1)
		printf("匹配成功，位置为:%d\n",a);
	else
		printf("匹配失败\n");
	return 0;
}
