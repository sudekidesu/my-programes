#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
string m[100005];
int main()
{
	long long n,k,l,i,j;
	long long a[100005];
	string s;
	long long temp,sum=0;
	map<string,long long> mapci;
	ios::sync_with_stdio(false);
	cin>>n>>k>>l;
	for(i=1;i<=n;i++)
		cin>>m[i];
	for(i=1;i<=n;i++)
	{
		cin>>j;
		mapci[m[i]]=j;
	}
	for(i=1;i<=k;i++)
	{
		cin>>n;
		temp=1000000000;
		for(j=1;j<=n;j++)
		{
			cin>>a[j];
			if(mapci[m[a[j]]]<temp)
				temp=mapci[m[a[j]]];
		}
		for(j=1;j<=n;j++)
			mapci[m[a[j]]]=temp;
	}
	for(i=1;i<=l;i++)
	{
		cin>>s;
		sum+=mapci[s];
	}
	cout<<sum<<endl;
}
