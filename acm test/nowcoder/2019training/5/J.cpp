#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MOD 998244353
long long qpow(long long a,long long b)
{
    long long ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long ans=0;;
    printf("%lld\n",qpow(3,n));
}
