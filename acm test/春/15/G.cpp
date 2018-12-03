#include<iostream>
using namespace std;
int main()
{
	long long n,m,i,t=1;
	cin>>m>>n;
	n-=m*2;
	for(i=n-m+1;i<=n;i++)
	{
		t*=i;
		t%=1000000007;
	}
	for(i=0;i<m;i++)
	{
		t*=6;
		t%=1000000007;
	}
	cout<<t<<endl;
	return 0;
}
