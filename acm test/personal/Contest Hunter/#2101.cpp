#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct point
{
    set<int> e;
    set<int> ans;
}p[30005];
set<int> s;
void dfs(int k)
{
    // printf("%d ",k);
    set<int>::iterator i;
    for(i=p[k].e.begin();i!=p[k].e.end();i++)
    {
        if(s.find(*i)==s.end())
        {
            s.insert(*i);
            dfs(*i);
        }
        for(set<int>::iterator j=p[*i].ans.begin();j!=p[*i].ans.end();j++)
            p[k].ans.insert(*j);
    }
    p[k].ans.insert(k);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        p[x].e.insert(y);
    }
    s.clear();
    // dfs(2);
    for(int i=1;i<=n;i++)
        if(s.find(i)==s.end())
        {
            // printf("\n");
            dfs(i);
            s.insert(i);
        }
    for(int i=1;i<=n;i++)
        printf("%d\n",p[i].ans.size());
}
