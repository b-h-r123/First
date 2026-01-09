#include<stdio.h>
#include<string.h>

int tonum(int num[],char str[])
{
    int n=strlen(str);
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            num[j]=str[i]-'0';
            j++;
        }
    }
    return j;
}

void insert(int num[],int count)
{
    int i,temp;
    for(i=1;i<count;i++)
    {
        temp=num[i];
        int j;
        for(j=i-1;j>=0 && num[j]<temp;j--)
        {
            num[j+1]=num[j];
        }
        num[j+1] = temp;
    }
}

int main()
{
    char str[100] = {0};
    scanf("%s",str);
    int num[100] = {0};
    int count=tonum(num,str);
    insert(num,count);
    int i;
    for(i=0;i<count;i++)
        printf("%d",num[i]);
    return 0;
}