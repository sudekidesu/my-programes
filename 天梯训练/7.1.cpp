#include<iostream>
#include<cstdio>
using namespace std;
void tnf(int *a);
int gcd(int a,int b);
int main()
{
	int n1[2],n2[2],a,i,n;
	cin>>n;
	scanf("%d/%d",&n1[0],&n1[1]);
	for(i=1;i<n;i++)
	{
		scanf("%d/%d",&n2[0],&n2[1]);
		a=n1[0]*n2[1]+n1[1]*n2[0];
		n1[0]=a;
		n1[1]*=n2[1];
		tnf(n1);
	}
	if(n1[0]==0)
		cout<<"0";
	else if(n1[0]>=0)
		if(n1[0]>n1[1]&&n1[0]%n1[1]!=0)
			cout<<n1[0]/n1[1]<<" "<<n1[0]%n1[1]<<"/"<<n1[1];
		else if(n1[0]>=n1[1])
			cout<<n1[0]/n1[1];
		else
			cout<<n1[0]<<"/"<<n1[1];
	else
		if(-n1[0]>n1[1]&&(-n1[0])%n1[1]!=0)
			cout<<"-"<<-n1[0]/n1[1]<<" "<<-n1[0]%n1[1]<<"/"<<n1[1];
		else if(-n1[0]>=n1[1])
			cout<<"-"<<-n1[0]/n1[1];
		else
			cout<<"-"<<-n1[0]<<"/"<<n1[1];
}
void tnf(int *a)
{
	int i=gcd(a[0],a[1]);
	a[0]/=i;
	a[1]/=i;
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
