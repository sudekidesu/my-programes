#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool jud[64];
int st[64];
int b[350];
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&st[i]);
            sum+=st[i];
        }
        sort(st,st+n);
        for(int o=1;o<=sum;o++)
        {
            if(o<st[n-1]||sum%o!=0)
                continue;
            memset(b,0,sizeof(b));
            int flag=true;
            for(int i=n-1;i>=0&&flag;i--)
            {
                int l=1,r=sum/o,mid;
                while(l<=r)
                {
                    mid=(l+r)>>1;
                    if(o-b[mid]>=st[i])
                        r=mid-1;
                    else
                        l=mid+1;
                }
                if(l<=sum/o)
                    b[l]+=st[i];
                else
                    flag=false;
            }
            if(flag)
            {
                printf("%d\n",o);
                break;
            }
        }
    }
}
