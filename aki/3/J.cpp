#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    long long h[4]={0,0,0,0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long long temp;
        scanf("%lld",&temp);
        h[(i-1)%3+1]+=temp;
    }
    long long w=0,y=0,p=0;
    long long l;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&l);
        w+=h[(2*i-2)%3+1]*l;
        y+=h[(2*i-1)%3+1]*l;
        p+=h[(2*i)%3+1]*l;
    }
    printf("%lld %lld %lld\n",y,p,w);
}
