#include<iostream>
using namespace std;
int main()
{
	int a=0,b=0,c,i,temp;
	for(i=0;i<3;i++)
	{
		cin>>temp;
		a+=temp;
	}
	for(i=0;i<3;i++)
	{
		cin>>temp;
		b+=temp;
	}
	cin>>c;
	if(a%5==0)
		a/=5;
	else
		a=a/5+1;
	if(b%10==0)
		b/=10;
	else
		b=b/10+1;
	if(c>=a+b)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
