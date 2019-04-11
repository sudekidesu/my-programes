#include<iostream>
#include<cstdio>
#include<cstring>
// #include<time.h>
using namespace std;
const long long maxm = 5000000 + 1;//点的数量
long long num[maxm];
bool ifprime[maxm]={false};
int prime[maxm];
int cnt=0;
// void search(long long a,long long k,long long n)
// {
//     for(long long i=0;a*prime[k]<maxm;i++)
//     {
//         if(i>0)
//         {
//             a*=prime[k];
//             num[a]=n+i;
//         }
//         if(k+1<cnt)
//             search(a,k+1,num[a]);
//     }
// }
void init()
{
    ifprime[1]=true;
    for(int i=2;i*2<maxm;i++)
        if(!ifprime[i])
            for(int j=2;j*i<maxm;j++)
                if(!ifprime[i*j])
                    ifprime[i*j]=true;
    // num[1]=0;
    for(int i=2;i<maxm;i++)
        if(!ifprime[i])
        {
            // prime[cnt++]=i;
            num[i]=1;
        }
    for(int i=1;i<maxm;i++)
        for(int j=1;j<=i&&j*i<maxm;j++)
            // if(num[i*j]==0)
                num[i*j]=num[i]+num[j];
    // for(int i=0;i<cnt;i++)
    // {
    //     int temp=prime[i];
    //     int c=1;
    //     for(int j=1;temp*j<maxm;j++)
    //     {
    //         if(j==prime[i])
    //         {
    //             temp*=prime[i];
    //             c++;
    //             j=1;
    //         }
    //         num[temp]+=c;
    //     }
    // }
    // search(1,0,0);
    for(int i=2;i<maxm;i++)
        num[i]+=num[i-1];
    return;
}
int main()
{
    // int time=clock();
    init();
    // printf("%d\n",clock()-time);
    long long n;
    scanf("%I64d",&n);
    while(n--)
    {
        long long a,b;
        scanf("%I64d %I64d",&a,&b);
        printf("%I64d\n",num[a]-num[b]);
    }
}
