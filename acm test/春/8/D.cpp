#include<iostream>
using namespace std;
int num[100005];
int main()
{
	int n,i,temp,m;
	while(scanf("%d",&n)!=EOF)
	{
		m=0;
		for(i=1;i<=n;i++)
			num[i]=0;
		for(i=1;i<=n;i++)
		{
			cin>>temp;
			num[temp]++;
		}
		for(i=1;i<=n;i++)
			if(num[i]>2)
			{
				m+=num[i]/2;
				num[i]%=2;
				if(num==0)
				{
					m--;
					num[i]=2;
				}
			}
		for(i=1;i<=n-2;i++)
			if(num[i]>=1&num[i+1]>=1&&num[i+2]>=1)
			{
				num[i]--;
				num[i+1]--;
				num[i+2]--;
				m++;
			}
		for(i=1;i<=n;i++)
			if(num[i]==2)
			{
				m+=num[i]/2;
				num[i]%=2;
			}
		cout<<m<<endl;
	}
}
