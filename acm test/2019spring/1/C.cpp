#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int ans=0;
    int num[100005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    int l=0,r=n-1;
    while(l<r)
        ans+=num[r--]-num[l++];
    printf("%d\n",ans);
}
