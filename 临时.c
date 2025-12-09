#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[81], longest[81] = "";
    int c;
    
    do
    {
        scanf("%s", str);
        if(strlen(str) > strlen(longest))
            strcpy(longest, str);
        
        // 跳过所有空白字符（空格、制表符等）
        while((c = getchar()) == ' ' || c == '\t')
        {
            // 继续跳过空白
        }
        
    } while(c != '\n');
    
    printf("最长的单词%s,长度为%d\n", longest, strlen(longest));
    return 0;
}
