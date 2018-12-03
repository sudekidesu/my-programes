#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char d[100005];
int main()
{
    long long T;
    scanf("%lld",&T);
    long long sum=0;
    while(T--)
    {
        sum=0;
        long long n;
        scanf("%s",d);
        n=strlen(d);
        for(long long i=0;i<n;i++)
        {
            sum+=(n-i)*(d[i]=='1'?1:2);
            if(i>0)
                sum+=i*(n-i)*(d[i]==d[i-1]?2:1);
        }
        printf("%lld\n",sum);
    }
}
