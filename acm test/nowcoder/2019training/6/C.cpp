#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int r[100005]={0};
int main()
{
    int n,m;
    pair<int,int> z[100005];
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&z[i].second);
    for(int i=0;i<m;i++)
        scanf("%d",&z[i].first);
    sort(z,z+m);
    for(int i=m-1;i>=0;i--)
    {
        if(z[i].second<=n)
        {
            n-=z[i].second;
            ans+=z[i].second*z[i].first;
        }
        else
        {
            ans+=n*z[i].first;
            break;
        }
    }
    printf("%lld\n",ans);
}
