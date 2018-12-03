#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	string str;
	cin>>n;
	for(i=1;;i++)
	{
		cin>>str;
		if(str=="End")
			break;
		if(!(i%(n+1)))
		{
			cout<<str<<endl;
			continue;
		}
		else
		{
			if(str=="JianDao")
				cout<<"ChuiZi"<<endl;
			if(str=="ChuiZi")
				cout<<"Bu"<<endl;
			if(str=="Bu")
				cout<<"JianDao"<<endl;
		}
	}
}
