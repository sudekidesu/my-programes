#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int dp[21][21];
int main()
{
    int num[21];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    // for(int i=0;i<6000;i++)
    //     for(int j=0;j<6000;j++)
    //         dp[i][j]=2;
    sort(num+1,num+n+1);
    int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int l=1,r=i-1,mid;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(num[mid]>=(num[i]<<1)-num[j])
                    r=mid-1;
                else
                    l=mid+1;
            }
            if(num[l]==(num[i]<<1)-num[j])
                dp[i][j]=dp[l][i]+1;
            else
                dp[i][j]=2;
            ans=max(ans,dp[i][j]);
            // for(int k=1;k<=6;k++)
            // {
            //     for(int o=1;o<=6;o++)
            //         printf("%d ",dp[k][o]);
            //     puts("");
            // }
            // puts("");
        }
    printf("%d\n",ans);
}
