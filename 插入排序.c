#include<stdio.h>
#define N 9

void insert(int a[])
{
    int i;
    for(i=1;i<N;i++)
    {
        int j,temp=a[i];
        for(j=i-1;j>=0 && a[j]<a[i];j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    insert(a);
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}