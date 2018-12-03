#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long num[60000][2]={0};
    long long n;
    scanf("%lld",&n);
    long long sum=0,temp=0,temp2=10000001;
    long long mx=0,my=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&num[i][0],&num[i][1]);
        if(num[i][0]>temp)
        {
            if(i>0&&num[i][1]>my)
                sum-=my;
            if(num[i][1]>my)
                mx=num[i][1];
            sum+=num[i][1];
            temp=num[i][0];
        }
        if(num[i][1]<temp2)
        {
            if(i>0&&num[i][0]>mx)
                sum-=mx;
            if(num[i][0]>mx)
                mx=num[i][0];
            sum+=num[i][0];
            temp2=num[i][1];
        }
    }
    printf("%lld\n",sum);
}
