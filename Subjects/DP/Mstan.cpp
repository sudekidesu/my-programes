#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2000;
int t, n, l, r, maxh;
int dp[maxn][2];

struct kim
{
    int l, r, h;
    bool operator < (const kim &k) //对平台的高度从小到大排序
    {
        return h < k.h;
    }
}node[maxn];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        scanf("%d%d%d%d", &n, &l, &r, &maxh);
        for (int j = 0; j < n; j++)
            scanf("%d%d%d", &node[j].l, &node[j].r, &node[j].h);
        node[n].l = l;
        node[n].r = l;
        node[n].h = r;

        sort(node, node + n);

        int lp, rp;
        for (int j = 0; j <= n; j++)
        {
            lp = rp = -1;
            for (int k = j - 1; k >= 0; k--)
            {
                if (lp == -1 && node[k].l <= node[j].l && node[k].r >= node[j].l) //如果左下方有平台可以下落
                    lp = k;
                if (rp == -1 && node[k].l <= node[j].r && node[k].r >= node[j].r) //如果右下方有平台可以下落
                    rp = k;
            }
            if (lp == -1&&node[j].h<=maxh)//两个平台高度差小于指定差maxh
                dp[j][0] = node[j].h;
            if (rp == -1&&node[j].h<=maxh)
                dp[j][1] = node[j].h;
            if (lp != -1 && node[j].h - node[lp].h <= maxh)
                dp[j][0] = min(dp[lp][0] + node[j].l - node[lp].l, dp[lp][1] + node[lp].r - node[j].l) + node[j].h - node[lp].h; //下落到平台考虑往左边还是往右边走 选最小值
            if (rp != -1 && node[j].h - node[rp].h <= maxh)
                dp[j][1] = min(dp[rp][1] + node[rp].r - node[j].r, dp[rp][0] + node[j].r - node[rp].l) + node[j].h - node[rp].h;
        }
        cout << dp[n][0]<< endl;


    }
    //system("pause");
}
