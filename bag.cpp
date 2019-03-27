#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[8][16]={0};
int main()
{
    int n=7;
    int w[8]={0,2,3,5,7,1,4,1};
    int p[8]={0,10,5,15,7,6,18,3};
    for(int i=1;i<=n;i++)
        for(int j=15;j>=w[i];j--)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
    printf("%d\n",dp[7][15]);
}
