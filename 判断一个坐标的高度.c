#include<stdio.h>
#include<math.h>

int main()
{
    double x,y;
    printf("请输入横坐标与纵坐标:");
    scanf("%lf,%lf",&x,&y);
    x=fabs(x);
    y=fabs(y);
    if((x-2)*(x-2) + (y-2)*(y-2) <= 1)
        printf("高为10m");
    else printf("高为0m");
    return 0;
}
