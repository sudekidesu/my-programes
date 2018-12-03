#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MOD=1e9+7;
char add[302];
char sch[100002];
int h[30];
int dp[302][100002];
int n, k;

int main()
{
    int i, j;
    int x;
	while(cin>>k>>n)
    {
        for(i=0;i<26;i++) cin>>h[i];
        cin>>add;
        cin>>sch;
        memset(dp, 0, sizeof(dp));
        for(i=n-1; i>=0; i--)
        {
            dp[k-1][i]=dp[k-1][i+1];
            if(sch[i]==add[k-1])
                dp[k-1][i]=(dp[k-1][i]+1)%MOD;
        }
        for(i=n-1; i>=0; i--)
        {
            x=h[sch[i]-'A']+1;
            for(j=k-2; j>=0; j--)
            {
                dp[j][i]=dp[j][i+1];
                if(sch[i]==add[j] && i+x<n)
                    dp[j][i]=(dp[j][i]+dp[j+1][i+x])%MOD;
            }
        }
        cout<<dp[0][0]<<endl;
    }
	return 0;
}
