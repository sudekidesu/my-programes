#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char num[2000];
int sum;
int main()
{
    int n,m,h;
    sum=0;
    scanf("%d %d %d",&n,&m,&h);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    if(sum<n)
        printf("-1\n");
    else if(sum-num[h]+1<n)
        printf("1\n");
    else
    {
        double ans=1;
        for(int i=2-num[h];i<=0;i++)
        {
            ans*=sum-n+i;
            ans/=sum+i-1;
        }
        printf("%.7lf\n",1-ans);
    }
}
