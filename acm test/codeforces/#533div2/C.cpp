#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
int main()
{
    long long int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    long long int dp[3];
    long long int temp[3]={0};
    long long int num[3];
    num[0]=num[1]=num[2]=(r-l+1)/3;
    for(long long int i=r;(i-l+1)%3;i--)
        num[(i-l)%3]++;
    dp[0]=num[0];
    dp[1]=num[1];
    dp[2]=num[2];
    for(long long int i=1;i<n;i++)
    {
        temp[0]=(dp[0]*num[0]%mod+dp[1]*num[2]%mod+dp[2]*num[1]%mod)%mod;
        temp[1]=(dp[0]*num[1]%mod+dp[1]*num[0]%mod+dp[2]*num[2]%mod)%mod;
        temp[2]=(dp[0]*num[2]%mod+dp[1]*num[1]%mod+dp[2]*num[0]%mod)%mod;
        dp[0]=temp[0];
        dp[1]=temp[1];
        dp[2]=temp[2];
    }
    printf("%lld\n",dp[0]);
}
