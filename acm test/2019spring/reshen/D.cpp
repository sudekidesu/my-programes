#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    double x1,y1,x2,y2;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    int ans=0;
    int n;
    scanf("%d",&n);
    double a,b,c;
    double a0=x1-x2;
    double b0=y2-y1;
    double c0=(x2-x1)*y1-x1*(y2-y1);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        double x;
        if(a==0&&a0!=0&&b!=0&&b0!=0)
            x=-c/b;
        if(a0==0&&a!=0&&b!=0&&b0!=0)
            x=-c0/b0;
        if(b==0&&a0!=0&&a!=0&&b0!=0)
            x=(a0*(c/a)+c0)/b0;
        if(b0==0&&a!=0&&b!=0&&a0!=0)
            x=(a*(c0/a0)+c)/b;
        if((a*b0==b*a0&&a!=0&&b!=0&&a0!=0&&b0!=0)||(b==0&&b0==0))
            continue;
        if(a!=0&&b!=0&&a0!=0&&b0!=0)
            x=(c*b0-b*c0)/(b*a0-a*b0);
        if((x>min(x1,x2)&&x<max(x1,x2))||((b*x1+c)*(b*x2+c)/(a*x1)/(a*x2)<0))
            ans++;
    }
    printf("%d\n",ans);
}

// (a*(c0/a0)+c)/b=x

// (c2b1-c1b2)/(a1b2-a2b1)
