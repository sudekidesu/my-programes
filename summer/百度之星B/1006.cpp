#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    long long m,n,k;
    long long a,b;
    long long sum=0;
    scanf("%I64d %I64d %I64d",&m,&n,&k);
    while(k--)
    {
      scanf("%I64d %I64d",&a,&b);
      sum+=min(m-a,min(a,min(n-b,b)));
    }
    printf("%I64d\n",sum);
  }
}
