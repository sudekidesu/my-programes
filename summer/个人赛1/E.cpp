#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,d,i,num=0;
	int point[1000];
	cin>>n>>d;
	for(i=0;i<n;i++)
		cin>>point[i];
	sort(point,point+n);
	for(i=0;i<n-1;i++)
	{
		if(point[i+1]-point[i]<2*d)
		;
		else if(point[i+1]-point[i]==2*d)
		num++;
		else if(point[i+1]-point[i]>2*d)
			num+=2;
	}
	cout<<num+2;
}
