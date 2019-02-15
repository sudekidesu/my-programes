#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[1000005]={0};
int ans[241]={0};
int main()
{
    for(int i=1;i<=1000;i++)
        for(int j=i;i*j<=1000000;j++)
            num[i*j]+=(i==j?1:2);
    for(int i=1000000;i>=1;i--)
        ans[num[i]]=i;
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]!=0?ans[n]:-1);
    }
}
