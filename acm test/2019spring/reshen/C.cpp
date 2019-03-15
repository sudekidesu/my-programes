#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int ans=0;
    pair<int,int> b[55];
    b[0].second=0;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&b[i].first,&b[i].second);
    for(int i=1;i<=n;i++)
        ans+=(b[i].first-1-b[i-1].second)%x+b[i].second-b[i].first+1;
    printf("%d\n",ans);
}
