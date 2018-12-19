#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
struct node
{
    int s;
    vector<pair<int,int>> e;
    city()
    {
        s=0x3fffffff;
    }
    void clear()
    {
        s=0x3fffffff;
        e.clear();
    }
    void add(int b,int w)
    {
        pair<int,int> temp;
        temp.first=b;
        temp.second=w;
        e.push_back(temp);
    }
    void erase(int b)
    {
        vector<pair<int,int>>::iterator i;
        for(i=e.begin();i!=e.end();i++)
            if(i->first==b)
            {
                e.erase(i);
                return;
            }
    }
};
struct graph
{
    node v[200];
    void add(int a,int b,int w)
    {
        v[a].add(b,w);
        v[b].add(a,w);
    }
    void del(int a,int b)
    {
        v[a].erase(b);
        v[b].erase(a);
    }
    void dj(int a,int b)
    {
        priority_queue<int> q;
        q.push(a);
        v[a].s=0;
        while(q.size()!=0)
        {
            //printf("%d ",q.size());
            int a=q.top();
            q.pop();
            for(int i=0;i<v[a].e.size();i++)
            {
                if(v[v[a].e[i].first].s>v[a].e[i].second+v[a].s)
                {
                    q.push(v[a].e[i].first);
                    v[v[a].e[i].first].s=v[a].e[i].second+v[a].s;
                }
            }
        }
    }
    void dfs(int k)
    {
        set<int> s;
        vector<pair<int,int>>::iterator i;
        for(i=v[k].e.begin();i!=v[k].e.end();i++)
        {
            if(s.find((*i).first)==s.end())
            {
                s.insert((*i).first);
                dfs((*i).first);
            }
        }
    }
    void bfs(int k)
    {
        set<int> s;
        queue<int> q;
        q.push(k);
        while(q.size()!=0)
        {
            int a=q.front();
            q.pop();
            for(int i=0;i<v[a].e.size();i++)
                if(s.find(v[a].e[i].first)==s.end())
                    q.push(v[a].e[i].first);
        }
    }
};
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);//m为点数，n为边数
    int a,b,w;
    graph g;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        g.add(a,b,w);
    }
    scanf("%d %d",&a,&b);
    g.dj(a,b);
    if(g.v[b].s==0x3fffffff)
        printf("-1\n");
    else
        printf("%d\n",g.v[b].s);
}
