#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long temp[70]={0,1,3};
unsigned long long ans[70]={0,1,3,5,9,13};
int main()
{
    for(int i=3;i<70;i++)
        temp[i]=temp[i-1]*2+1;
    {
        ans[i]=0x7fffffff;
        for(int j=0;j<i;j++)
            ans[i]=min(ans[i],2*ans[j]+temp[i-j]);
    }
    int a;
    while(scanf("%d",&a)!=EOF)
        printf("%lld\n",ans[a]);
}
