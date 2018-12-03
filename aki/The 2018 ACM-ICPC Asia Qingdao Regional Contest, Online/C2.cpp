#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 1;
const int mod = 256;

struct node
{
    char s[4];
    int a, qu;
    /*
    bool operator < (const struct node a) const{
        return qu < a.qu;
    }*/
} q[maxn];
//map< pair<struct node, int>, int > mp;
bool mp[10005][257];
int r = 0;
int n = 0;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        r = 0;
        memset(mp,0,sizeof(mp));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            char tem[4];
            scanf("%s", tem);
            strcpy(q[i].s, tem);
            if (!strcmp(tem, "add"))
            {
                scanf("%d", &q[i].a);
                q[i].qu = 0;
            }
            else
            {
                scanf("%d %d", &q[i].a, &q[i].qu);
            }
        }
        int k = 1;
        bool flag = true;
        while (k <= n)
        {
            if (k > n)
            {
                flag = true;
            }
            mp[k][r]=true;
            if (mp[k][r])
            {
                flag = false;
                break;
            }
            if (!strcmp(q[k].s, "add"))
            {
                r = (r + q[k].a) % mod;
                k++;
            }
            else if (!strcmp(q[k].s, "beq"))
            {
                if (q[k].a == r)
                {
                    k = q[k].qu;
                }
                else
                {
                    k++;
                }
            }
            else if (!strcmp(q[k].s, "bne"))
            {
                if (q[k].a != r)
                {
                    k = q[k].qu;
                }
                else
                {
                    k++;
                }
            }
            else if (!strcmp(q[k].s, "blt"))
            {
                if (r < q[k].a)
                {
                    k = q[k].qu;
                }
                else
                {
                    k++;
                }
            }
            else if (!strcmp(q[k].s, "bgt"))
            {
                if (r > q[k].a)
                {
                    k = q[k].qu;
                }
                else
                {
                    k++;
                }
            }
        }
        /*
        for(int i = 1; i <= n; i++){
            cout<<q[i].s<<" "<<q[i].a<<" "<<q[i].qu<<endl;
        }
        */
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
