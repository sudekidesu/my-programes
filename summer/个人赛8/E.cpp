#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m;
	if(m>n/2)
		k=max(1,m-1);
	if(m<=n/2)
		k=min(n,m+1);
	cout<<k;
}
