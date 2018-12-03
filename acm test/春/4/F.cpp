#include<iostream>
using namespace std;
int main()
{
	int o,t;
	char str[2][7];
	cin>>t;
	for(o=0;o<t;o++)
	{
		cin>>str[0]>>str[1];
		cout<<"Case "<<o+1<<": ";
		if(str[0][0]>str[1][0])
			cout<<">";
		else if(str[0][0]<str[1][0])
			cout<<"<";
		else
			cout<<"=";
		if(str[0][1]!=str[1][1])
		{	
			if(str[0][0]>str[1][0])
				cout<<" >"<<endl;
			else if(str[0][0]<str[1][0])
				cout<<" <";
			else
				if(str[0][2]>str[1][2])
				cout<<" >"<<endl;
			else if(str[0][2]<str[1][2])
				cout<<" <"<<endl;
			else
			{
				if(str[0][3]>str[1][3])
					cout<<" >"<<endl;
				else if(str[0][3]<str[1][3])
					cout<<" <"<<endl;
				else
					cout<<" ="<<endl;
			}
		}
		else
			if(str[0][2]>str[1][2])
				cout<<" >"<<endl;
			else if(str[0][2]<str[1][2])
				cout<<" <"<<endl;
			else
			{
				if(str[0][3]>str[1][3])
					cout<<" >"<<endl;
				else if(str[0][3]<str[1][3])
					cout<<" <"<<endl;
				else
				{
					if(str[0][4]>str[1][4])
						cout<<" >"<<endl;
					else if(str[0][4]<str[1][4])
						cout<<" <"<<endl;
					else
					{
						if(str[0][5]>str[1][5])
							cout<<" >"<<endl;
						else if(str[0][5]<str[1][5])
							cout<<" <"<<endl;
						else
							cout<<" ="<<endl;
					}
				}
			}
	}
}
