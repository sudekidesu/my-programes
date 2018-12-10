#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
int num1=0,num2=0;
int n,m,a,b;
struct node
{
    vector<int> u,n;
    node()
    {
        u.clear();
        n.clear();
    }
}t[100000];
int cnt[100000];
void upsearch(int k)
{
    if(k==b)
    {
        num1++;
        return;
    }
    for(int i=0;i<t[k].u.size();i++)
        upsearch(t[k].u[i]);
}
void downsearch(int k)
{
    if(k==b)
    {
        num2++;
        return;
    }
    for(int i=0;i<t[k].n.size();i++)
        downsearch(t[k].n[i]);
}
void upsearch2(int k)
{
    cnt[k]++;
    for(int i=0;i<t[k].u.size();i++)
        upsearch(t[k].u[i]);
}
void downsearch2(int k)
{
    cnt[k]++;
    for(int i=0;i<t[k].n.size();i++)
        downsearch(t[k].n[i]);
}
bool youbuge()
{
    int yao,ling;
    int temp=1;
    while(t[temp].u.size()!=0)
        temp=t[temp].u[0];
    yao=temp;
    while(t[temp].n.size()!=0)
        temp=t[temp].n[0];
    ling=temp;
    set<int> s;
    s.clear();
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            bool flag=true;
            memset(cnt,0,sizeof(cnt));
            upsearch2(i);
            upsearch2(j);
            for(int k=1;k<=n;k++)
                if(cnt[k]>1&&k!=yao)
                    flag=false;
            memset(cnt,0,sizeof(cnt));
            downsearch2(i);
            downsearch2(j);
            for(int k=1;k<=n;k++)
                if(cnt[k]>1&&k!=ling)
                    flag=false;
            if(flag)
            {
                s.insert(i);
                s.insert(j);
            }
        }
    if(s.size()==n)
        return true;
    else
        return false;
}
int main()
{
    printf("请输入元素个数<空格>关系数\n");
    scanf("%d %d",&n,&m);
    printf("请输入a<空格>b来表示a≤b\n");
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        t[b].n.push_back(a);
        t[a].u.push_back(b);
    }
    printf("请输入a<空格>b来查询a与b的盖住关系\n");
    scanf("%d %d",&a,&b);
    num1=0;
    num2=0;
    upsearch(a);
    downsearch(a);
    if(num1==1&&num2==0)
        printf("b盖住a\n");
    else if(num2==1&&num1==0)
        printf("a盖住b\n");
    else
        printf("无盖住关系\n");
    printf("%s有补格\n",youbuge()?"是":"不是");
}
