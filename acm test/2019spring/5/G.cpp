#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
deque<long long> q;
int num[100005][3]={0};
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i][0]);
    int max=-1;
    int temp=n-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i][1]);
        if(num[i][1]==0)
            num[i][2]=num[i][0]+num[i-1][2];
        else
            num[i][2]=num[i-1][2];
        if(i>=k-1&&num[i][2]-num[i-k][2]>max)
        {
            temp=i;
            max=num[i][2]-num[i-k][2];
        }
    }
    for(int i=temp;i>temp-k;i--)
        num[i][1]=1;
    int ans=0;
    for(int i=0;i<n;i++)
        if(num[i][1])
            ans+=num[i][0];
    printf("%d\n",ans);
}
