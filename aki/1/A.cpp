#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2][10001]={0};
int ct[2][10001]={0};
int main()
{
    int k,n;
    int num[26]={0};
    char s[1005];
    char m[10005];
    scanf("%d %d",&k,&n);
    for(int i=0;i<26;i++)
        scanf("%d",&num[i]);
    s[0]='\n';
    scanf("%s",s+1);
    scanf("%s",m+1);
    for(int i=0;i<=n;i++)
    	dp[0][i]=dp[1][i]=1;
    for(int i=1;i<=k;i++)
    {
    	int cnt=0;
    	ct[0][0]=ct[1][0]=1;
        for(int j=i;j<=n;j++)
        {
            if(m[j]==s[i])
            {
        		cnt+=ct[i%2][i];
                dp[i%2][j]=ct[(i+1)%2][j];
                for(int l=1;l<=num[m[j]-'A'];l++)
                    ct[i%2][j+l]-=ct[(i+1)%2][j];
            }
            ct[i%2][j]+=cnt;
        }
        memset(ct[(i+1)%2],0,sizeof(ct[(i+1)%2]));
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(m[i]==s[n])
            ans+=dp[n%2][i];
    printf("%lld\n",ans);
}
