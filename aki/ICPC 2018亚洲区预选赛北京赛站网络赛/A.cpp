#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000+100;
const int INF = 0x3f3f3f3f;

int head[maxn];
int tot;

struct Point
{
    int v, next, w;
    Point(int _v, int _w, int _next)
    {
        v = _v;
        w = _w;
        next = _next;
    }
}edge[4*maxn];

void init()
{
    tot = 0;
    for(int i = 0; i < maxn; i++)
    {
        head[i] = -1;
    }
}

void addedge(int u, int v, int w)
{
    egde[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

struct qnode
{
    int v, w;
    qnode(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
}

priority_queue<qnode> que;
int dis[maxn];
bool vis[maxn];
void dij(int n, int st)
{
    for(int i = 0; i <= n; i++)
    {
        vis[i] = false;
        dis[i] = INF;
    }
    while(!que.empty()) que.pop();
    dis[st] = 0;
    que.push(qnode(st, 0));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        if(vis[tmp.v])  continue;
        int u = tmp.v, w  tmp.w;
        for(int i = head[u]; ~i; i = edge[i].next)
        {

        }
    }
}

string s[100+20];
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        init();
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(s[i][j])
            }
    }
}
