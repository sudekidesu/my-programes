#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
struct city
{
    vector<int> a;
}c[105];
int num=0;
int ans=0;
int endd;
set<int> s;
void search(int k)
{
    s.insert(k);
    vector<int>::iterator i;
    for(i=c[k].a.begin();i!=c[k].a.end();i++)
    {
        if(s.find(*i)!=s.end()||*i==endd)
            continue;
        search(*i);
    }
    num++;
}
int main()
{
    int m,n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        ans=0;
        for(int i=0;i<105;i++)
            c[i].a.clear();
        while(scanf("%d",&m)&&m!=0)
        {
            while(getchar()!='\n')
            {
                int b;
                scanf("%d",&b);
                c[m].a.push_back(b);
                c[b].a.push_back(m);
            }
        }
        for(int i=1;i<=n;i++)
        {
            endd=i;
            num=0;
            s.clear();
            search(*(c[i].a.begin()));
            if(num!=n-1)
                ans++;
        }
        printf("%d\n",ans);
    }
}
