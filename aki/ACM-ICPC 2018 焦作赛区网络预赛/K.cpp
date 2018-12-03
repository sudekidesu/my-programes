#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;

int v[30],c[30];
int dp[10010],V;
//v数组存价值，c数组存数量，V是总容量
void ZeroOne(int cost,int weight)//01背包
{
    for(int i = V; i >= cost; i--)
        dp[i] = max(dp[i],dp[i-cost]+weight);
}

void Complete(int cost,int weight)//完全背包
{
    for(int i = cost; i <= V; i++)
        dp[i] = max(dp[i],dp[i-cost]+weight);
}

void Multiple(int cost,int weight,int amount)//多重背包
{
    int k;
    if(cost*amount>=V)
    {
        Complete(cost,weight);
        return;
    }
    k=1;
    while(k<amount)
    {
        ZeroOne(k*cost,k*weight);
        amount=amount-k;
        k=k*2;
    }
    ZeroOne(amount*cost,amount*weight);
}
int main()
{
    int N,M,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&M);
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d",&v[i],&c[i]);
        }
        while(M--)
        {
            scanf("%d",&V);
            for(int i = 0; i <= V; i++)//初始化：是否恰好装满背包
                dp[i] = -0xffffff0;
            dp[0] = 0;
            for(int i = 0; i < N; i++)
                Multiple(v[i],v[i],c[i]);
            int ans = 0;
            for(int i = 1; i <= V; i++)
            if(dp[i] >= 0)
                ans++;
      		printf("%d\n",ans);
        }
    }
    return 0;
}
