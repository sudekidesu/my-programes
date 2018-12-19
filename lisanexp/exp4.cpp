#include<iostream>
#include<cstdio>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
struct node
{
    set<int> e;
    node()
    {
        e.clear();
    }
}v[10000];
int n;
set<int> t;
void search(int k)
{
    if(t.find(k)!=t.end())
        return;
    t.insert(k);
    set<int>::iterator i;
    for(i=v[k].e.begin();i!=v[k].e.end();i++)
        search(*i);
}
int main()
{
    int seed=time(NULL);
    srand(seed);
    n=random(4,8);
    int ne=random(n-1,n*(n-1)/2);
    while(t.size()!=n)
    {
        for(int i=1;i<=n;i++)
            v[i].e.clear();
        for(int i=0;i<ne;i++)
        {
            int a=random(1,n),b=random(1,n);
            if(a==b||v[a].e.find(b)!=v[a].e.end())
            {
                i--;
                continue;
            }
            v[a].e.insert(b);
            v[b].e.insert(a);
        }
        t.clear();
        search(1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(v[i].e.size()&1)
            cnt++;
    if(cnt==0||cnt==2)
    {
        printf("%d\n",n);
        set<int>::iterator j;
        for(int i=1;i<=n;i++)
            for(j=v[i].e.begin();j!=v[i].e.end();j++)
                if(*j>i)
                    printf("%d %d\n",i,*j);
    }
}
