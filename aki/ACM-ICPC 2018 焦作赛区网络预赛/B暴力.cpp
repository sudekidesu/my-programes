#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long num[2000];
char s[2000];
long long n,m,k;
long long maxx=0;
void dfs(long long p,long long q,long long t)
{
    for(int i=t+1;i<=n;i++)
    {
        int temp;
        switch(s[q])
        {
            case '+':temp=p+num[i];break;
            case '-':temp=p-num[i];break;
            case '*':temp=p*num[i];break;
            case '/':temp=p/num[i];break;
        }
        if(q!=m)
            dfs(temp,q+1,i);
        else
            if(temp>maxx)
                maxx=temp;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&num[i]);
        scanf("%s",s+1);
        maxx=0;
        dfs(k,1,0);
        printf("%lld\n",maxx);
    }
}
