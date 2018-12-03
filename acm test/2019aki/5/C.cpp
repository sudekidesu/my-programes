#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n,r;
    int T=1;
    while(scanf("%d %d",&n,&r)&&n!=0)
    {
        double ans[20]={0},num[20]={0},an=0;;
        long long flag=-1;
        double t=1;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&num[i]);
            t*=1-num[i];
        }
        long long f=pow(2,n);
        while(flag<f-1)
        {
            double a=1;
            flag++;
            double tt=t;
            int cnt=0;
            long long temp=flag;
            for(int i=0;i<n;i++)
            {
                if(temp%2==1)
                {
                    cnt++;
                    a*=num[i];
                }
                else
                    a*=(1-num[i]);
                temp>>=1;
            }
            if(cnt!=r)
                continue;
            an+=a;
            temp=flag;
            for(int i=0;i<n;i++)
            {
                if(temp%2==1)
                    tt=tt/(1-num[i])*num[i];
                temp>>=1;
            }
            temp=flag;
            for(int i=0;i<n;i++)
            {
                if(temp%2==1)
                    ans[i]+=tt;
                temp>>=1;
            }
        }
        printf("Case %d:\n",T++);
        for(int i=0;i<n;i++)
            printf("%lf\n",ans[i]/an);
    }
}
