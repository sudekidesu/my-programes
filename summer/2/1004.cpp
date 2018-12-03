#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int i,k;
	int ifprime[600];
	for(i=0;i<600;i++)
		ifprime[i]=1;
	for(i=2;i<600;i++)
	{
		if(ifprime[i]==0)
			continue;
		for(k=2;k*i<600;k++)
			ifprime[k*i]=0;
	}
	while(scanf("%d",&k)!=EOF)
	{
		if(k<=6)
			cout<<"Yes"<<endl;
		else if(ifprime[k]==1)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
 } 

