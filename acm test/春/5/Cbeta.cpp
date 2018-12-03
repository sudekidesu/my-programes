#include<iostream>
#include<algorithm>
#include<cstdio>

 using namespace std;

 int main()
 {
 	double dp[10010];
 	int cost[10010];
 	double value[10010];
 	int i,j,m,n;
 	for(;;)
 	{
 		cin>>n>>m;
 		if(m==0&&n==0)
 			return 0;
 		for(i=1;i<=m;i++)
 			cin>>cost[i]>>value[i];
 		for(i=0;i<=n;i++)
 			dp[i]=1;
 		for(i=1;i<=m;i++)
 			for(j=n;j>=cost[i];j--)
 				dp[j]=min(dp[j],dp[j-cost[i]]*(1-value[i]));
 		printf("%.1lf%%\n",100*(1-dp[n]));
	 }
 }
 
