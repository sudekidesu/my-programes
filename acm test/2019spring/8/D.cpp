#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int num[300000]={0};
int ans[300000]={0};
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        scanf("%d",&num[i]);
    int cnt=0;
    int b=n;
    while(b>=1)
    {
        ans[cnt++]=b;
        b=num[b];
    }
    while(--cnt>=0)
        printf("%d%c",ans[cnt],cnt==0?'\n':' ');
}
