#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point
{
    long long x,y;
}p[60000];
vector<pair<long long,long long>> mx;
vector<pair<long long,long long>> my;
long long sum=0;
void binsearchx(long long x,long long y)
{
    vector<pair<long long,long long>>::iterator l=mx.begin(),r=mx.end()-1,mid;
    while(l>=r)
    {
        mid=l+(r-l)/2;
        if((*mid).first<x)
            l=mid+1;
        else
            r=mid-1;
    }
    if((*l).second>=y)
        return;
    if((*l).first>x)
    {
        pair<long long,long long> a;
        a.first=0;
        a.second=0;
        mx.push_back(a);
        for(r=mx.end()-1;r>l;r--)
            *r=*(r-1);
        sum+=y-(*(l-1)).second;
        (*l).first=x;
        (*l).second=y;
    }
    else
    {
        sum+=y-(*l).second;
        (*l).second=y;
    }
}
void binsearchy(long long x,long long y)
{
    vector<pair<long long,long long>>::iterator l=my.begin(),r=my.end()-1,mid;
    while(l>=r)
    {
        mid=l+(r-l)/2;
        if((*mid).first<y)
            l=mid+1;
        else
            r=mid-1;
    }
    if((*l).second>=x)
        return;
    if((*l).first>y)
    {
        pair<long long,long long> a;
        a.first=0;
        a.second=0;
        my.push_back(a);
        for(r=my.end()-1;r>l;r--)
            *r=*(r-1);
        sum+=x-(*(l-1)).second;
        (*l).first=y;
        (*l).second=x;
    }
    else
    {
        sum+=x-(*l).second;
        (*l).second=x;
    }
}
int main()
{
    pair<long long,long long> a;
    a.first=0;
    a.second=0;
    mx.push_back(a);
    my.push_back(a);
    a.first=10000000;
    a.second=0;
    mx.push_back(a);
    my.push_back(a);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&p[i].x,&p[i].y);
    sum+=p[n-1].x+p[n-1].y;
    for(int i=n-2;i>=0;i--)
    {
        binsearchx(p[i].x,p[i].y);
        binsearchy(p[i].x,p[i].y);
    }
    printf("%lld\n",sum);
}
