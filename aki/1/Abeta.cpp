#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[2][100005];
int main()
{
    long long num[26];
    long long k,n;
    char s[100005];
    char m[100005];
    while(scanf("%lld %lld",&k,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(long long i=0;i<26;i++)
            scanf("%lld",&num[i]);
        scanf("%s",s+1);
        scanf("%s",m+1);
        for(long long i=1;i<=n;i++)
        {
            dp[1][i]=dp[1][i-1];
            if(s[1]==m[i])
                dp[1][i]++;
        }
        char t=s[1];
        for(long long i=2;i<=k;i++)
        {
            for(long long j=num[t-'A']+1;j<=n;j++)
            {
                dp[i%2][j]=dp[i%2][j-1];
                if(s[i]==m[j])
    	            dp[i%2][j]+=dp[(i-1)%2][j-num[t-'A']-1];
    	        dp[i%2][j]%=1000000007;
            }
            t=s[i];
        }
        printf("%lld\n",dp[k%2][n]);
    }
}
