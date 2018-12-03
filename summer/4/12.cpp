#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int T;
	int a[200000],i;
	double b;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b=sqrt(a[n-1]-a[0]>0?a[n-1]-a[0]:a[0]-a[n-1]);
		i=b;
		printf("%d\n",i);
	}
 } 
