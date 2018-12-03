#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 2e5 + 5;

int T,n,top,back;
int a[N];
int R[N];
int s[N];

int find(int val)
{
    int l = 0, r = top;
    int ans = -1;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(s[mid] < val) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

void solve()
{
    back = 1, top = 1;
    s[top] = a[1];
    int ans = 1;
    for(int i=2;i<=n;i++)
    {
        ans = max(ans, find(a[i]) + R[i]);
        if(a[i] > a[i-1]) back++;
        else back = 1;
        if(back > top) s[++top] = a[i];
        else s[back] = min(s[back], a[i]);
    }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        R[n] = 1;
        for(int i=n-1;i>=1;i--) R[i] = a[i] < a[i+1] ? R[i+1] + 1 : 1;
        solve();
    }
    return 0;
}
