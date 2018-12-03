#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	long long a,b,na,nb;
	cin>>n;
	int i,j;
	if(n==1)
		cout<<"1"<<endl<<"9"<<endl<<"0"<<endl<<"-72"<<endl;
	else if(n<10)
	{
		a=pow(10,n)-50;
		na=a-81*(n-2)-25;
		b=pow(10,n-1)+9;
		nb=b-82;
		cout<<a<<endl<<b<<endl<<na<<endl<<nb<<endl;
	}
	else
	{
		for(i=0;i<n-2;i++)
			printf("9");
		cout<<"50"<<endl;
		printf("1");
		for(i=0;i<n-2;i++)
			printf("0");
		cout<<"9"<<endl;
		for(i=1;i<=n-9;i++)
			printf("9");
		na=999999950-81*(n-2)-25;
		cout<<na<<endl;
		for(i=1;i<=n-3;i++)
			printf("9");
		printf("27\n");
	}
}
