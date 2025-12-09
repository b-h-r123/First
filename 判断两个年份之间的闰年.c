#include<stdio.h>

int runyear(int y);

int main()
{
    int sy,ty,n=0,i;
    printf("请输入起止年份:");
    scanf("%d %d",&sy,&ty);
    for(i=sy;i<=ty;i++)
    {
        if(runyear(i))
        {
            printf("%d ",i);
            n++;
            if(n%10 == 0)
                putchar('\n');
        }
    }
    if(n%10 != 0)
        putchar('\n');
     printf("共有%d个闰年\n",n);   
    return 0;
}

int runyear(int y)
{
    if((y%4 == 0 && y%100 != 0) || y%400 == 0)
        return 1;
    else return 0;
        
}
