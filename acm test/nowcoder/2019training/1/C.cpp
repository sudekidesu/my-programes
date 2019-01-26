#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int num[3005]={0};
    int ans[3005]={0};
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
            ans[i]=max(ans[i],ans[j]^num[i]);
    printf("%d\n",ans[n-1]>0?ans[n-1]:-1);
}
