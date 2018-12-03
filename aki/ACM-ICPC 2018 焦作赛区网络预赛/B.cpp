#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long dp[10][2000][2]={0};
long long num[2000];
char s[2000];
long long n,m,k;
int main()
{
    long long T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<10;i++)
        	for(int j=0;j<1005;j++)
        	{
        		dp[i][j][0]=10000000000000000;
				dp[i][j][1]=-10000000000000000;
			}
        scanf("%lld %lld %lld",&n,&m,&dp[0][0][1]);
        dp[0][0][0]=dp[0][0][1];
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            dp[0][i][1]=dp[0][i-1][1];
            dp[0][i][0]=dp[0][i-1][0];
        }
        scanf("%s",s+1);
        for(long long i=1;i<=m;i++)
        {
        	long long j;
            for(j=i;j<=n-m+i;j++)
            {

                switch(s[i])
                {
                    case '+':
                        dp[i][j][1]=max(max(dp[i-1][j-1][1]+num[j],dp[i-1][j-1][0]+num[j]),dp[i][j-1][1]);
                        dp[i][j][0]=min(min(dp[i-1][j-1][1]+num[j],dp[i-1][j-1][0]+num[j]),dp[i][j-1][0]);
                        break;
                    case '-':
                        dp[i][j][1]=max(max(dp[i-1][j-1][1]-num[j],dp[i-1][j-1][0]-num[j]),dp[i][j-1][1]);
                        dp[i][j][0]=min(min(dp[i-1][j-1][1]-num[j],dp[i-1][j-1][0]-num[j]),dp[i][j-1][0]);
                        break;
                    case '*':
                        dp[i][j][1]=max(max(dp[i-1][j-1][1]*num[j],dp[i-1][j-1][0]*num[j]),dp[i][j-1][1]);
                        dp[i][j][0]=min(min(dp[i-1][j-1][1]*num[j],dp[i-1][j-1][0]*num[j]),dp[i][j-1][0]);
                        break;
                    case '/':
                        dp[i][j][1]=max(max(dp[i-1][j-1][1]/num[j],dp[i-1][j-1][0]/num[j]),dp[i][j-1][1]);
                        dp[i][j][0]=min(min(dp[i-1][j-1][1]/num[j],dp[i-1][j-1][0]/num[j]),dp[i][j-1][0]);
                        break;
                }
            }
            if(j==n-m+i)
                	switch(s[i])
	                {
	                    case '+':
	                        dp[i][j][1]=dp[i-1][j-1][1]+num[j];
	                        dp[i][j][0]=dp[i-1][j-1][0]+num[j];
	                        break;
	                    case '-':
	                        dp[i][j][1]=dp[i-1][j-1][1]-num[j];
	                        dp[i][j][0]=dp[i-1][j-1][0]-num[j];
	                        break;
	                    case '*':
	                        dp[i][j][1]=max(dp[i-1][j-1][1]*num[j],dp[i-1][j-1][0]*num[j]);
	                        dp[i][j][0]=min(dp[i-1][j-1][1]*num[j],dp[i-1][j-1][0]*num[j]);
	                        break;
	                    case '/':
	                        dp[i][j][1]=max(dp[i-1][j-1][1]/num[j],dp[i-1][j-1][0]/num[j]);
	                        dp[i][j][0]=min(dp[i-1][j-1][1]/num[j],dp[i-1][j-1][0]/num[j]);
	                        break;
	                }
        }
        long long maxx=-10000000000000000;
        for(int i=1;i<=n;i++)
        	if(maxx<dp[m][i][1])
        		maxx=dp[m][i][1];
        printf("%lld\n",maxx);
    }
}
