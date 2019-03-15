#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int ans=-0x3fffffff;
int num[300005];
int dp[4];
int cnt;
int main()
{
    int n,m;
    int sum=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<n;i++)
    {
        if(dp[1]<0)
        {
            while(dp[1]<0&&dp[2]>0)
            {
                dp[1]-=num[i-dp[2]];
                dp[2]--;
            }
        }
        dp[1]+=num[i];
        dp[2]++;
        if(dp[2]>m)
        {
            dp[1]-=num[i-m];
            dp[2]--;
        }
        if(num[i]>0)
        {
            if(dp[0]<0)
            {
                dp[0]=0;
                dp[3]=0;
            }
            dp[0]+=num[i];
            dp[3]++;
            if(dp[3]>m)
            {
                dp[0]-=num[i-m];
                dp[3]--;
            }
            ans=max(dp[0],ans);
        }
        else
        {
            dp[0]=0;
            dp[3]=0;
        }
        if(dp[2]>0)
            ans=max(dp[1],ans);
    }
    for(int i=n;i<n+m;i++)
    {
        if(dp[1]<0)
        {
            while(dp[1]<0&&dp[2]>0)
            {
                dp[1]-=num[i-dp[2]];
                dp[2]--;
            }
        }
        dp[2]++;
        if(dp[2]>m)
        {
            dp[1]-=num[i-m];
            dp[2]--;
        }
        if(dp[2]>0&&i-dp[2]<n-1)
            ans=max(dp[1],ans);
    }
    printf("%d\n",ans);
}
