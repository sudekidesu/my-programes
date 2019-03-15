#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    int a[505];
    int o[1005];
    int ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<t;i++)
        scanf("%d",&o[i]);
    for(int i=0;i<t;i++)
    {
        set<int> s;
        for(int j=1;o[i-j]!=o[i]&&i-j>=0;j++)
            if(s.find(o[i-j])==s.end())
            {
                s.insert(o[i-j]);
                ans+=a[o[i-j]];
            }
    }
    printf("%d\n",ans);
}
