#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long num[200][2];
    long long n,x;
    scanf("%lld %lld",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&num[i][0],&num[i][1]);
    for(int i=n-1;i>=0;i--)
    {
        if(num[i][0]==1)
            x-=num[i][1];
        else if(num[i][0]==2)
            x+=num[i][1];
        else if(num[i][0]==3)
            x/=num[i][1];
        else
            x*=num[i][1];
    }
    printf("%lld\n",x);
}
