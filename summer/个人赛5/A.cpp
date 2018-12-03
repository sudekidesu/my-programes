#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,k;
	cin>>n>>k;
	while(k--)
		cin>>i>>j;
	for(i=0;i<n;i++)
		cout<<i%2;
}
