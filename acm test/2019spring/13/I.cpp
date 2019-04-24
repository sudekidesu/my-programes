#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool b[1005]={false};
int num;
int ans;
int n,m;
struct swit
{
    bool k[1005]={false};
}s[1005];
int main()
{
    scanf("%d %d",&m,&n);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a;
        scanf("%d",&a);
        b[a]=true;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        for(int j=1;j<=t;j++)
        {
            int a;
            scanf("%d",&a);
            s[i].k[a]=true;
        }
    }
    bool flag=true;
    int ans=0;
    for(int i=1;i<=m&&flag;i++)
    {
        bool flag1=true;
        for(int j=1;j<=n;j++)
        {
            b[j]^=s[i].k[j];
            if(b[j])
                flag1=false;
        }
        ans++;
        if(flag1)
            flag=false;
    }
    for(int i=1;i<=m&&flag;i++)
    {
        bool flag1=true;
        for(int j=1;j<=n;j++)
        {
            b[j]^=s[i].k[j];
            if(b[j])
                flag1=false;
        }
        ans++;
        if(flag1)
            flag=false;
    }
    if(flag)
        printf("-1\n");
    else
        printf("%d\n",ans);
}
