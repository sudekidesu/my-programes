#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long int i;
	long long int t1=0,t2=1,t;
	for(i=0;i<15000;i++)
	{
		t1%=10000;
		t2%=10000;
		printf("%lld,",t1);
		t=t2;
		t2+=t1;
		t1=t;
	}
}
