#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int r[100005]={0};
int main()
{
    long long n,m,d,x;
    scanf("%lld %lld %lld %lld",&n,&m,&d,&x);
    long long temp=0;
    for(long long i=0;i<=x;i++)
    {
        temp+=n+i*d;
        // printf("%d ",n+i*d);
        if(temp>=m)
        {
            printf("%lld\n",i+1);
            break;
        }
    }
}
