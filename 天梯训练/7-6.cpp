#include<iostream>
using namespace std;
int main()
{
	int n,i,j=0,o=0,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a%2)
			j++;
		else
			o++;
	}
	cout<<j<<" "<<o;
}
