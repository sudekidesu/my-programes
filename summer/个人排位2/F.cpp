#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long int n;
	long long int sur[100000]={0};
	long long int i;
	long long int en=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
		scanf("%I64d",&sur[i]);
	while((n--)>1)
	{
		sort(sur,sur+n+1);
		sur[1]+=sur[0];
		en+=sur[1];
		sur[0]=sur[n];
	}
	printf("%I64d\n",en); 
}
