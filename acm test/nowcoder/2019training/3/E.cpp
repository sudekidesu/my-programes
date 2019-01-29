#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    int n,m;
    int ans=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        ans=n-1+n*(m-2);
        if(m%2)
            ans+=n-1;
        if(m==1)
            ans=n-2;
        printf("%d\n",ans);
    }
}
