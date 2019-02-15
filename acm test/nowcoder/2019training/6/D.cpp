#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int n;
    long long ans=0;
    long long temp;
    long long pre=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&temp);
        if(temp==0)
        {
            ans+=pre/2;
            pre=0;
        }
        else
            pre+=temp;
    }
    ans+=pre/2;
    printf("%lld\n",ans);
}
