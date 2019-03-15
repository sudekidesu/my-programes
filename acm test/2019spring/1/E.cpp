#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int ans[50];
    scanf("%d",&n);
    for(int i=0;i<50;i++)
        ans[i]=i;
    do
    {
        for(int i=0;i<n;i++)
            printf("%d%c",ans[i]+1,i==n-1?'\n':' ');
    }while(next_permutation(ans,ans+n));
}
