#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long s=0,n;
    long long l;
    scanf("%lld",&l);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        long long a,b;
        scanf("%lld %lld",&a,&b);
        s+=a*b;
    }
    printf("%lld",s/l);
}
