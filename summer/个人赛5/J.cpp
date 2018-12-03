#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int g[1000];
	int n,i,num=0;
	double sum=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>g[i];
		sum+=g[i];
	}
	sort(g,g+n);
	for(i=0;sum/n<4.5;i++)
	{
		sum+=5-g[i];
		g[i]=5;\
		num++;
	}
	cout<<num;
}
