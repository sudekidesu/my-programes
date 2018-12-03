#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a+c>b+d)
			cout<<"1"<<endl;
		else if(a+c<b+d)
			cout<<"2"<<endl;
		else if(c>b)
			cout<<"1"<<endl;
		else if(b>c)
			cout<<"2"<<endl;
		else
			cout<<"-1"<<endl;
	}
 } 
