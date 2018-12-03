#include<iostream>
#include<algorithm>
using namespace std;
long long g(long long a,long long b)
{
	long long num=1;
	long long i;
	for(i=a+1;i<=b;i++)
		num*=i;
	for(i=1;i<=b-a;i++)
		num/=i;
	return num;
}
int main()
{
	long long nan,nv,n;
	cin>>nan>>nv>>n;
	long long i,num=0;
	for(i=(4>n-nv)?4:(n-nv);i<=nan&&i<=n-1;i++)
		num+=g(i,nan)*g(n-i,nv);
	cout<<num;
}
