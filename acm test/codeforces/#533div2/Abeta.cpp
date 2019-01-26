#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a[100000];
    int sum[100000]={0};
    int n;
    int tt,at;
    int t=0;
    int ans=0x3f3f3f3f;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=100;i++)
    {
        at=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]>i+1)
                at+=a[j]-i-1;
            if(a[j]<i-1)
                at+=i-1-a[j];
        }
        if(at<ans)
        {
            t=i;
            ans=at;
        }
    }
    printf("%d %d\n",t,ans);
}
