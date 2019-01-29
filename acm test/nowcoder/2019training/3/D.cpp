#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmpWA(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.second>b.second)
        return true;
    else if(a.second<b.second)
        return false;
    else if(a.first<b.first)
        return true;
    else
        return false;
}
bool cmpAC(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first*b.second<a.second*b.first)
        return true;
    else
        return false;
}
int main()
{
    int n;
    long long ans=0;
    pair<long long,long long> a[100005];
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].first,&a[i].second);
        sum+=a[i].second;
    }
    sort(a,a+n,cmpAC);
    for(int i=0;i<n;i++)
    {
        sum-=a[i].second;
        ans+=sum*a[i].first;
    }
    printf("%lld\n",ans);
}
