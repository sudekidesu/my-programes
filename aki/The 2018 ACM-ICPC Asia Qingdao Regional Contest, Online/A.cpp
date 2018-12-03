#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        m-=n;
        m++;
        printf("%d %d\n",n,n/m+(n%m==0?0:1));
    }
}
