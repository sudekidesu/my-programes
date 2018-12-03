#include<iostream>
using namespace std;
int main()
{
	int a,b,i,j;
	char c;
	cin>>a>>c;
	if(a%2==0)
		b=a/2;
	else
		b=a/2+1;
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
			cout<<c;
		cout<<endl;
	}
}
