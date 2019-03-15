#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    return b==0?a:gcd(b,a%b);
}
unsigned long long f(unsigned long long a,unsigned long long b)
{
    if(b==0)
        return 0;
    else
        return 1+f(a,b-gcd(a,b));
}
int main()
{
    unsigned long long x,y;
    scanf("%lld %lld",&x,&y);
    int ans=0;
    unsigned long long temp=1;
    while(y)
    {
        if(x==y)
        {
            ans++;
            break;
        }
        temp=gcd(x,y);
        unsigned long long d=y/temp-x/temp;
        ans+=d;
        y-=d*temp;
    }
    printf("%6d\n",ans);
}
