#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long t[1000000];
int main()
{
	long long n,k,l,i,j,j2,num;
	long long sum=0;
	cin>>n>>k>>l;
	for(i=1;i<=n*k;i++)
		cin>>t[i];
	sort(t+1,t+1+n*k);
	if(t[n]-t[1]>l)
		sum=0;
	else if(n==1)
		sum=t[1];
	else if(k==1)
		for(i=1;i<=n;i++)
			sum+=t[i];
	else
	{
		sum=0;
		for(i=1;i<=n*k&&t[i]-t[1]<=l;i++);
		i--;
		j2=i;
		j=(i-n)/(k-1)+((i-n)%(k-1)?1:0); 
		for(i=1;j>0;i+=k)
		{
			sum+=t[i];
			j--;
			n--;
		}
		for(i=j2;n>0;i--)
		{
			sum+=t[i];
			n--;
		}

	}
	cout<<sum;
}
