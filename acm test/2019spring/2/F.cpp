#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,m;
int num[50005];
int jud(int k)
{
    int r=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]-r>=k)
        {
            cnt++;
            r=num[i];
        }
        if(i==n-1&&num[i]-r<k)
            cnt--;
    }
    return cnt;
}
int main()
{
    scanf("%d %d %d",&L,&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    n++;
    num[n-1]=L;
    sort(num,num+n);
    int l=1,r=1000000000,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(jud(mid)<=n-m)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",l-1);
}
