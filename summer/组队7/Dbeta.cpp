#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[1000000];
int n,b;
long long count(int t)
{
    long long cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=num[i]/t+(num[i]%t==0?0:1);
    return cnt>b;
}
int main()
{
    while(1)
    {
        scanf("%d %d",&n,&b);
        if(n==-1)
        	break;
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int l=1,r=*max_element(num+1,num+n+1),mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(count(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",l);
    }
}
