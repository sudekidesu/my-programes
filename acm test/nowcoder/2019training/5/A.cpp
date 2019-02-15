#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int r[100005]={0};
int main()
{
    int T;
    double n,m;
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a<b)
        swap(a,b);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %lf",&n,&m);
        double temp=sqrt(m*m+n*n);
        if(temp>=a-b&&temp<=a+b)
            printf("0.00000000\n");
        else
            printf("%.8lf\n",temp<a-b?a-b-temp:temp-a-b);
    }
}
