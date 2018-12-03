#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long num[60000][2];
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&num[i][0],&num[i][1]);
    set<long long> x;
    set<long long> y;
    x.insert(0);
    x.insert(10000001);
    y.insert(0);
    y.insert(10000001);
    long long sum=0;
    set<long long>::iterator p;
    for(int i=n-1;i>=0;i--)
    {
        p=x.lower_bound(num[i][0]);
        p--;
        sum+=num[i][0]-(*p);
        x.insert(num[i][0]);
        p=y.lower_bound(num[i][1]);
        p--;
        sum+=num[i][1]-(*p);
        y.insert(num[i][1]);
    }
    printf("%lld\n",sum);
}
