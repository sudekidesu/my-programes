#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,num[100000];
long long ans=0;
void quick_sort(long long *l,long long *r)
{
    if(l>=--r)
        return;
    long long *a=l;
    for(long long *i=l;i<r;i++)
        if(*i<*r)
        {
            if(i!=a)
                ans++;
            swap(*i,*(a++));
        }
    swap(*a,*r);
    if(a!=r)
        ans++;
    quick_sort(l,a);
    quick_sort(++a,++r);
}
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%lld",&num[i]);
        ans=0;
        quick_sort(num,num+n);
        printf("%d\n",ans);
    }
}
