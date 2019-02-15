#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int r[100005]={0};
int main()
{
    int n,m;
    int a,b;
    bool ans=true;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        r[i]=i;
    while(m--)
    {
        scanf("%d %d",&a,&b);
        while(r[a]!=a)
            a=r[a];
        r[b]=a;
        if(a==b)
            ans=false;
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
