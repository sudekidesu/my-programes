#include<iostream>
using namespace std;
int main()
{
	int n,a=0,b=1,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		b=1;
		for(j=1;j<=i;j++)
			b*=j;
		a+=b;
	}
	cout<<a;
}
