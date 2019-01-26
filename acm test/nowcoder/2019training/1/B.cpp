#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long num[100005]={0};
    long long n,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    sort(num,num+n+1);
    int l=0,r=n;
    while(l<r)
    {
        ans+=(num[l]-num[r])*(num[l]-num[r]);
        l++;
        if(l>=r)
            break;
        ans+=(num[l]-num[r])*(num[l]-num[r]);
        r--;
    }
    printf("%lld\n",ans);
}
