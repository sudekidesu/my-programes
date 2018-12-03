#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxm (int)1000
bool jud[maxm+5];
long long num[maxm+5];
int main()
{
    memset(jud,1,sizeof(jud));
    memset(num,0,sizeof(num));
    freopen("init2.data","w",stdout);
    for(long long i=2;i<=maxm;i++)
        if(jud[i])
            for(long long j=1;j*i*i<=maxm;j++)
                jud[j*i*i]=false;
    for(int i=1;i<=maxm;i++)
    {
        num[i]=num[i-1];
        for(int j=1;j*j<=i;j++)
            if(i%j==0&&jud[j]&&jud[i/j])
                if(j*j==i)
                    num[i]++;
                else
                    num[i]+=2;
        printf("%lld,",num[i]-num[i-1]);
    }
    int j=2;
    for(int i=1;i<1000;i++)
        if(num[i]-num[i-1]==2)//{
            printf("%d,",i);//num[i]-num[i-1]);j=i;}
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        printf("%lld",num[m]);
    }
}
