#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long a, b,shu[20],dp[20][2];

long long dfs(long long len, bool if6, bool shangxian)
{
    if (len == 0)
        return 1;
    if (!shangxian && dp[len][if6])
        return dp[len][if6];
    long long cnt = 0, maxx = (shangxian ? shu[len] : 9);
    for (long long i = 0; i <= maxx; i++)
    {
        if (i == 6)
            continue;
        cnt += dfs(len - 1, i == 6, shangxian && i == maxx);
    }
    return shangxian ? cnt : dp[len][if6] = cnt;
}

long long solve(long long x)
{
    memset(shu, 0, sizeof(shu));
    long long k = 0;
    while (x)
    {
        shu[++k] = x % 10;
        x /= 10;
    }
    return dfs(k, false, true);
}

int main()
{
    scanf("%lld%lld", &a, &b);
    printf("%lld\n",b-a+1- solve(b) + solve(a - 1));


    return 0;
}
