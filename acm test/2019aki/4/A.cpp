#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct emp
{
    int h;
    int p;
    set<int> s;
    emp()
    {
        p=0;
    }
    void clear()
    {
        p=0;
        s.clear();
    }
}e[7000];
pair<int,int> search(int p)
{
    set<int>::iterator i;
    pair<int,int> temp,ans;
    ans.first=ans.second=0;
    for(i=e[p].s.begin();i!=e[p].s.end();i++)
    {
        temp=search(*i);
        ans.first+=temp.second;
        ans.second+=max(temp.first,temp.second);
    }
    ans.first+=e[p].h;
    return ans;
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int sum=0;
        for(int i=0;i<7000;i++)
            e[i].clear();
        for(int i=1;i<=N;i++)
            scanf("%d",&e[i].h);
        int L,K;
        while(scanf("%d %d",&L,&K)&&L!=0&&K!=0)
        {
            e[K].s.insert(L);
            e[L].p=K;
        }
        int t;
        pair<int,int> temp;
        for(int i=1;i<=N;i++)
            if(e[i].p==0)
            {
                temp=search(i);
                sum+=max(temp.first,temp.second);
            }
        printf("%d\n",sum);
    }
}
