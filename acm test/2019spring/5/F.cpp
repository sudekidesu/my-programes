#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int num[100005]={0};
int main()
{
    int n,t,c,ans=0;
    scanf("%d %d %d",&n,&t,&c);
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp>t)
            num[i]=num[i-1]+1;
        else
            num[i]=num[i-1];
        if(i>=c&&num[i]==num[i-c])
            ans++;
    }
    printf("%d\n",ans);
}
