#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct point
{
    int m1,m2;
    vector<pair<int,int>> a;
    point()
    {
        m1=0;
        m2=0;
    }
}p[10005];
int maxm=0;
void search(int k,int f)
{
    vector<pair<int,int>>::iterator i;
    for(i=p[k].a.begin();i!=p[k].a.end();i++)
    {
        if((*i).first==f)
            continue;
        search((*i).first,k);
        if(p[(*i).first].m1+(*i).second>p[k].m2)
            p[k].m2=p[(*i).first].m1+(*i).second;
        if(p[k].m2>p[k].m1)
            swap(p[k].m2,p[k].m1);
    }
    if(p[k].m1+p[k].m2>maxm)
        maxm=p[k].m1+p[k].m2;
}
int main()
{
    int a,b,c;
    int t=5;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        pair<int,int> temp;
        temp.first=a;
        temp.second=c;
        p[b].a.push_back(temp);
        temp.first=b;
        p[a].a.push_back(temp);
    }
    search(1,0);
    printf("%d\n",maxm);
}
