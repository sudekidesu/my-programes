#include<iostream>
using namespace std;
int main()
{
	int n,i,j,num1,num0,num=0;
	int ge[1000];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>ge[i];
	for(j=0;j<=n;j++)
	{
		num0=num1=0;
		for(i=0;i<j;i++)
			if(ge[i]==0)
				num0++;
		for(;i<n;i++)
			if(ge[i]==1)
				num1++;
		if(num1+num0>num)
			num=num1+num0;
	}
	cout<<num<<endl;
}
