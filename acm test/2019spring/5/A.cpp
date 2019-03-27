#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int num[100005]={0};
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        num[i]=num[i-1]+temp;
    }
    int ans=0;
    for(int i=n-1;i>=1;i--)
        if(num[i]*2==num[n])
            ans++;
    printf("%d\n",ans);
}
