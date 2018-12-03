#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long num,m,n,i;
	for(;;)
	{
		cin>>n>>m;
		if(m==0&&n==0)
			break;
		num=0;
		if(n>m)
		{
			i=n;
			n=m;
			m=i;
		}
		for(i=1;i<n;i++)
			num+=(i-1)*i/2;
		num*=2;
		num+=(m-n+1)*(n-1)*n/2;
		num*=2;
		num+=(n-1)*n*m/2+(m-1)*n*m/2;
		num*=2;
		cout<<num<<endl;
	}
	return 0;
 }
