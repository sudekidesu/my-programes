#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    pair<double,double> a[4],b[4];
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a[0].first,&a[0].second,&a[1].first,&a[1].second,&a[2].first,&a[2].second,&a[3].first,&a[3].second);
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&b[0].first,&b[0].second,&b[1].first,&b[1].second,&b[2].first,&b[2].second,&b[3].first,&b[3].second);
    bool flag=false;
    for(int i=0;i<4;i++)
    {
        if((((b[1].second-b[0].second)/(b[1].first-b[0].first)*a[i].first+(b[0].second/b[0].first-b[1].second/b[1].first)/(b[1].second-b[0].second)-a[i].second)*((b[3].second-b[2].second)/(b[3].first-b[2].first)*a[i].first+(b[3].second/b[2].first-b[3].second/b[2].first)/(b[3].second-b[2].second)-a[i].second)<=0&&
        ((b[3].second-b[0].second)/(b[3].first-b[0].first)*a[i].first+(b[0].second/b[0].first-b[3].second/b[3].first)/(b[3].second-b[0].second)-a[i].second)*((b[1].second-b[2].second)/(b[1].first-b[2].first)*a[i].first+(b[1].second/b[2].first-b[1].second/b[2].first)/(b[1].second-b[2].second)-a[i].second)<=0)||
        (((a[1].second-a[0].second)/(a[1].first-a[0].first)*b[i].first+(a[0].second/a[0].first-a[1].second/a[1].first)/(a[1].second-a[0].second)-b[i].second)*((a[3].second-a[2].second)/(a[3].first-a[2].first)*b[i].first+(a[3].second/a[2].first-a[3].second/a[2].first)/(a[3].second-a[2].second)-b[i].second)<=0&&
        ((a[3].second-a[0].second)/(a[3].first-a[0].first)*b[i].first+(a[0].second/a[0].first-a[3].second/a[3].first)/(a[3].second-a[0].second)-b[i].second)*((a[1].second-a[2].second)/(a[1].first-a[2].first)*b[i].first+(a[1].second/a[2].first-a[1].second/a[2].first)/(a[1].second-a[2].second)-b[i].second)<=0))
            flag=true;
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}
