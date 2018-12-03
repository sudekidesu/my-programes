#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a,i,j,s[10]={1,1,1,1,1,1,1,1,1,1};
	double b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		b=sqrt(a);
		if(a==2)
			continue;
		else if(a==1||!(a%2))
			s[i]=0;
		else
			for(j=3;j<=b;j++)
			{
				if(!(a%j))
				{
					s[i]=0;
					break;
				}
			}
	}
	for(i=0;i<n;i++)
	{
		if(s[i])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
