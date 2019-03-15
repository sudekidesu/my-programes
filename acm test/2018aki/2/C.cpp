#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int h[300005];
int ans[300005];
map<int,int> mmp;
set<int> s;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        mmp[h[i]]=i;
    }
    set<int>::iterator k;
    for(int i=n-1;i>=0;i--)
    {
        k=s.lower_bound(h[i]);
        if(k==s.begin())
            ans[i]=-1;
        else
        {
            k--;
            ans[i]=mmp[*k]-i+ans[mmp[*k]];
            // printf("%d %d %d\n",mmp[*k],i,ans[mmp[*k]]);
        }
        s.insert(h[i]);
    }
    for(int i=0;i<n;i++)
        printf("%d%c",ans[i],i==n-1?'\n':' ');
}
