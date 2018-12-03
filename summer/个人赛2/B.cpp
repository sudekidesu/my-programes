#include<iostream>
#include<cstdio>
#include<algorithm>
long long a[300000];
using namespace std;
int main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	a[0]=a[1]-1;
	if(n>1&&k<n&&a[k+1]==a[k])
	{
		printf("-1");
		return 0;
	}
	else
		printf("%lld",a[k]>=1&&a[k]<=1000000000?a[k]:-1);
}
