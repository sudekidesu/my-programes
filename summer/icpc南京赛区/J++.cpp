#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxm (int)2e7
int num[maxm+5];
bool ifprime[10000000];//1为素数，0为和数
void prime()
{
	int i,k;
	memset(ifprime,1,sizeof(ifprime));
	ifprime[0]=ifprime[1]=false;
	for(i=2;i<10000000;i++)
		if(ifprime[i])
			for(k=2;k*i<10000000;k++)
				ifprime[k*i]=false;
 }
int main()
{
    memset(num,0,sizeof(num));
    prime();
    for(int i=2;i<=maxm;i++)
        if(ifprime[i])
        {
            num[i]=2;
            for(int j=i+1;j*i<=maxm;j++)
                if(ifprime[j])
                    num[i*j]=4;
            if(i<=271)
            {
                for(int k=i*i*i;k<=maxm;k+=k)
                    num[k]=0;
            }
        }
    num[1]=1;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        int sum=0;
        for(int i=1;i<=m;i++)
            sum+=num[i];
        printf("%d",sum);
    }
}
