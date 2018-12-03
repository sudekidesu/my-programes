#include<iostream>
#include<cstdio>
using namespace std;
int sum=0;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    return b==0?a:gcd(b,a%b);
}
unsigned long long f(unsigned long long a,unsigned long long b)
{
    sum++;
    if(b==0)
        return 0;
    else
    {
        unsigned long long temp=gcd(a,b);
        if(temp==a)
            return b/a;
        if(temp==b)
            return 1;
        return 1+f(a,b-temp);
    }
}
int main()
{
    unsigned long long x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",f(x,y));
    printf("%d\n",sum);
}
