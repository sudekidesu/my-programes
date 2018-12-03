#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,j;
	long long mono[200000];
	long long dp[200000][2];
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		dp[i][0]=0;
		dp[i][1]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		mono[j]++;
	}
	for(i=0;i<=100000;i++)
	{
		if(mono[i]==0)
			continue;
		for(j=n;j>=1;j++)
		{
			if(dp[j-1][0]+mono[i]*i>dp[j][0]&&dp[j][1]==0)
			{
				dp[j][0]=dp[j-1][0]+mono[i]*i;
				dp[j][1]=1;
			}
			else
				dp[j][1]=0;
		}
	}
	printf("%lld",dp[n][1]);
}
