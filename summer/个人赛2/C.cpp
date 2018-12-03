#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,L,k,i,S=0,H=0;
	int h[110000];
	scanf("%d %d %d",&n,&L,&k);
	for(i=0;i<n;i++)
		scanf("%d",&h[i]);
	sort(h+1,h+n);
	for(i=0;i<n;i++)
	{
		S+=h[i];
		if(L*h[0]/S>=k)
			H=i+1;
	}
	i=n-1;
	printf("%d",n-H);
}
