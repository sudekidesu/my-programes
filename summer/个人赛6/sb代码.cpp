#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long mono[200000];
long long dp[200000]={0};
long long num[200000]={0};
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
	{
		scanf("%lld",&mono[i]);
		num[mono[i]]++;
	}
    dp[1]=1*num[1];
    for(j=2;j<100005;j++)
        dp[j]=max(dp[j-1],dp[j-2]+j*num[j]);
    printf("%lld",*max_element(dp,dp+100005));
}
