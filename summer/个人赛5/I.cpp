#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,min=1000000005;
	int q[200000];
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>q[i];
		if(q[i]<min)
			min=q[i];
	}
	if(min>n)
		for(i=1;i<=n;i++)
			q[i]-=min/n*n;
    for(i=1;;i++)
    {
    	if(i>n)
    	{
			for(i=1;i<=n;i++)
				q[i]-=n;
			i=0;
		}
		else if(q[i]<i)
			break;
	}
	cout<<i<<endl;
}
