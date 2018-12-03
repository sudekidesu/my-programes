#include<iostream>
using namespace std;
int main()
{
	int a,b,c,i,temp;
	double j;
	cin>>a>>b>>c;
	cout<<a/b<<".";
	a%=b;
	a*=10;
	for(i=0;i<c-1;i++)
	{
		cout<<a/b;
		a%=b;
		a*=10;
	}
	j=a*1.0/b;
	temp=j+0.5;
	cout<<temp<<endl;
 }
