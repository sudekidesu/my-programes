#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	string arr;
	int i=0,fu=0;
	float er=0;
	cin>>arr;
	if(arr[0]=='-')
	{
		i++;
		fu=1;
	}
	for(;i<arr.size();i++)
	{
		if(arr[i]=='2')
			er++;
	}
	er/=arr.size()-fu;
	if(fu==1)
		er*=1.5;
	if(arr[arr.size()-1]%2==0)
		er*=2;
	printf("%.2f%%",er*100);
}
