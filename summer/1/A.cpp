#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	long long z,n,a,b,c,m;
	int T,i,j;
	int num[20];
	scanf("%d",&T);
	while(T--)
	{
		a=b=c=0;
		scanf("%lld",&z);
		n=z;
		for(i=0;n!=0;i++)
		{
			num[i]=n%2;
			n/=2;
		}
		i--;
		for(j=i;j>0;j--)
			if(num[j]==1&&num[j-1]==1)
			{
				a+=pow(2,j-1);
				b+=pow(2,j-1);
				c+=pow(2,j-1);
				num[j]=0;
				num[j-1]=0;
			}
		j=0;
		for(;i>=0;i--)
		{
			if(num[i]==1)
			{
				if(a<=b&&a<=c)
					a+=pow(2,i);
				else if(b<=c)
					b+=pow(2,i);
				else
					c+=pow(2,i);
			}
		}
		m=a*b*c;
		if(m==0)
			printf("-1\n",m);
		else
			printf("%lld\n",m);
	}
}
