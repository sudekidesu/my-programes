#include<iostream>
using namespace std;
int main()
{
	int n,l,i;
	int bu,h=1000000;
	cin>>n>>l;
	for(i=0;i<n;i++)
	{
		cin>>bu;
		if(l%bu==0&&l/bu<h)
			h=l/bu;
	}
	cout<<h;
}
