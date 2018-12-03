#include<iostream>
using namespace std;
int main()
{
	long long n,i,num;
	cin>>n;
	num=n;
	num-=n/2;
	num-=n/3;
	num-=n/5;
	num-=n/7;
	num+=n/6;
	num+=n/10;
	num+=n/14;
	num+=n/15;
	num+=n/21;
	num+=n/35;
	num-=n/30;
	num-=n/42;
	num-=n/105;
	num-=n/70;
	num+=n/210;
	cout<<num;
}
