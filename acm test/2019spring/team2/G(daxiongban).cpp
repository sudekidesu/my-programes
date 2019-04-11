#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000+10;
long long n, k, num[maxn], res[maxn];
priority_queue<long long, vector<long long>, greater<long long> > que;
int main()
{
    scanf("%lld%lld", &n, &k);
    for(long long i = 0; i < n; i++)
    {
        scanf("%lld", &num[i]);
    }
    sort(num, num+n);
    int ind = 0;
    for(long long i = 0; i < n; i++)
    {
        while(!que.empty() && que.top() <= num[i])
        {
            res[ind++] = num[i];
            if(ind >= k) break;
            que.pop();
        }
        int tmp = ind;
        if(ind >= k) break;
        res[ind++] = num[i];
        for(int j = 0; j < tmp; j++)
        {
            if(i < n-1 && que.size() < k && num[i]+res[j] > num[i+1])
                que.push(num[i]+res[j]);
            else
                res[ind++] = num[i]+res[j];
        }
        if(ind >= k) break;
    }
    printf("%lld", res[k-1]);
}
