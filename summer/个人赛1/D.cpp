#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j;
	int num[1005],num2[1005];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
		num2[i]=num[i];
	}
	sort(num2,num2+n);
	for(i=0;i<n;i++)
	{
		if(num2[i]%2==1)
		{
			for(j=0;j<n;j++)
				if(num[j]==num2[i])
					num[j]++;
			for(j=0;j<n;j++)
				if(num[j]==num2[i]+1)
					num[j]--;
		}
		if(num2[i]%2==0)
		{
			for(j=0;j<n;j++)
				if(num[j]==num2[i])
					num[j]--;
		}
	}
	cout<<num[0];
	for(i=1;i<n;i++)
		cout<<" "<<num[i];
}
