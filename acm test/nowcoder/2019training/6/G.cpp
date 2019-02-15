#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long long l,r;
    while(scanf("%lld %lld",&l,&r)!=EOF)
    {
        bool a[100]={false};
        long long temp=r-l;
        int b=0;
        while(temp>0)
        {
            a[b++]=true;
            temp>>=1;
        }
        b=0;
        while(r>0)
        {
            if(r&1)
                a[b]=true;
            r>>=1;
            b++;
        }
        b=0;
        while(l>0)
        {
            if(l&1)
                a[b]=true;
            l>>=1;
            b++;
        }
        long long ans=0;
        temp=1;
        for(int i=0;i<100;i++,temp<<=1)
            if(a[i])
                ans+=temp;
        printf("%lld\n",ans);
    }
}
