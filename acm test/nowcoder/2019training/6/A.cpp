#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int r[100005]={0};
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    long long temp=0;
    for(long long i=0;i<=m&&6*i<=n;i++)
        if(((n-6*i)%8%7==0&&((n-6*i)/8+(n-6*i)%8/7))||((n-6*i)%8%9==0&&((n-6*i)/8+(n-6*i)%8/9)))
        {
            printf("%lld\n",i);
            return 0;
        }
    printf("jgzjgzjgz\n");
}
