#include<iostream>
#include<algorithm>
using namespace std;
typedef struct mono
{
	int t,d,p;
}mono;
bool b(mono a,mono b)
{
	if(a.d<b.d)
		return true;
	else
		return false;
}
int main()
{
	int dp[2005];
	int i,j;
	mono a[105];
	int n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i].t>>a[i].d>>a[i].p;
	for(i=0;i<2005;i++)
		dp[i]=0;
	sort(a,a+n,b);
	for(i=0;i<n;i++)
	{
		for(j=a[i].d-1;j>=a[i].t;j--)
			dp[j]=max(dp[j],dp[j-a[i].t]+a[i].p);
		for(j=a[i].d;j<a[n-1].d;j++)
			dp[j]=max(dp[j],dp[a[i].d-1]);
	}
	cout<<dp[a[n-1].d-1];
}
