#include<iostream>
using namespace std;
int main()
{
	int num,ge[1005];
	int n,i,st=0,en=0,en0=0,en1=0;
	int num0=0,num1=0;
	cin>>n;
	num=n;
	for(i=0;i<n;i++)
		cin>>ge[i];
	for(i=0;ge[i]==0&&i<n;i++)
		st++;
	for(i=n-1;ge[i]==0&&i>=0;i--)
		en0++;
	for(;ge[i]==1&&i>=0;i--)
		en1++;
	if(en0<=en1)
		num-=en0;
	en=en0+en1;
	for(i=st;i<n-en;i++)
	{
		if(ge[i]==0)
			num0++;
		if(ge[i]==1)
			num1++;
	}
	if(num1>=num0)
		num-=num0;
	else
		num-=num1;
	cout<<num;
}
