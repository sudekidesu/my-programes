#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,n,m=0,s=0,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		s+=a;
		if(s<m)
			m=s;
	}
	cout<<-m<<endl;
	return 0;
}
