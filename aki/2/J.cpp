#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int num[2000000]={0};
struct noods
{
    vector<int> a;
    int n;
    noods()
    {
        a.clear();
        n=0;
    }
}nood[2000000];
void dfs(int be,int fr)
{
    vector<int>::iterator i;
    for(i=nood[be].a.begin();i!=nood[be].a.end();i++)
    {
        if(*i==fr)
            continue;
        dfs(*i,be);
        nood[be].n+=nood[*i].n;
    }
    nood[be].n++;
    if(nood[be].n!=n)
    {
        for(int j=1;j*j<=nood[be].n;j++)
            if(nood[be].n%j==0)
            {
                num[j]++;
                if(j*j!=nood[be].n)
                    num[nood[be].n/j]++;
            }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        nood[a].a.push_back(b);
        nood[b].a.push_back(a);
    }
    dfs(1,0);
    int flag=0;
    for(int i=n-1;i>0;i--)
        if(num[i]==n/i-1&&n%i==0)
        {
            if(flag==1)
                printf(" ");
            else
                flag=1;
            printf("%d",num[i]);
        }
    printf("\n");
}
