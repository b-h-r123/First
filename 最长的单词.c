#include<stdio.h>
#include<string.h>

int main()
{
	char arr[100];
	int len=0,n=0,i,count=0,longest=0,start;
	printf("请输入一串单词:");
	fgets(arr, sizeof(arr), stdin); 
	len = strlen(arr);
	if(len > 0 && arr[len-1] == '\n')
	{
		arr[len-1] = '\0';
		len--; 
	}
	
	if(len == 0)
	{
		printf("输入为空\n");
		return 0;
	}
	
	char pre = ' ';
	char now;
	for(i=0;i<len;i++)
	{
		now = arr[i];
		if(pre != ' ' && now == ' ')
		{
			if(count>longest)
			{
				longest = count;
				n = start;
			}
			count = 0; 
		}
		else if(pre == ' ' && now != ' ')
		{
			count++;
			start = i;
		}
		else if(pre != ' ' && now != ' ')
		{
			count++;
		}
		pre = now;
	}
	if(count>longest)
	{
		longest = count;
		n = start;
	}
	printf("最长的单词为:");
	for(i=n;i<n+longest;i++)
		printf("%c",arr[i]);
	printf("\n长度为%d\n",longest); 
	return 0;
}
