#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long mono[100005]={0};
long long dp[100005]={0};
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		mono[j]++;
	}
	dp[1]=mono[1]*1;
	for(i=2;i<100005;i++)
		dp[i]=max(dp[i-1],dp[i-2]+mono[i]*i);
	printf("%lld",*max_element(dp,dp+100004));
}
