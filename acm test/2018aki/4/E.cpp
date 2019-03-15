#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct city
{
    int s;
    vector<int> a;
    vector<int> w;
    city()
    {
        s=0x3fffffff;
    }
};
int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        city c[205];
        int a,b,w;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            c[a].a.push_back(b);
            c[b].a.push_back(a);
            c[a].w.push_back(w);
            c[b].w.push_back(w);
        }
        scanf("%d %d",&a,&b);
        queue<int> q;
        q.push(a);
        c[a].s=0;
        while(q.size()!=0)
        {
            //printf("%d ",q.size());
            int a=q.front();
            q.pop();
            for(int i=0;i<c[a].a.size();i++)
            {
                if(c[c[a].a[i]].s>c[a].w[i]+c[a].s)
                {
                    q.push(c[a].a[i]);
                    c[c[a].a[i]].s=c[a].w[i]+c[a].s;
                        // printf("%d %d %d %d\n",c[a].a[i],c[c[a].a[i]].s,c[a].w[i],c[a].s);
                }
            }
        }
        if(c[b].s==0x3fffffff)
            printf("-1\n");
        else
            printf("%d\n",c[b].s);
    }
}
