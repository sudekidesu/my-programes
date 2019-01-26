#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a[100000];
    int sum[100000]={0};
    int n;
    int t=0;
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)
            sum[i]=a[i];
        else
            sum[i]=a[i]+sum[i-1];
    }
    sort(a,a+n);
    if(n&1)
        t=a[n/2];
    else
        t=(a[n/2]+a[n/2+1])/2;
    for(int i=0;i<n;i++)
    {
        if(a[i]>t)
            ans+=a[i]-t-1;
        else if(a[i]<t)
            ans+=t-1-a[i];
    }
    printf("%d %d\n",t,ans);
}
