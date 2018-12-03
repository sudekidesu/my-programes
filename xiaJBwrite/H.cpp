#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int m,n,num=0;
	cin>>m>>n;
	int i,j,gmax,a,b,o;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			gmax=gcd(i,j);
			a=i/gmax;
			b=j/gmax;
			for(o=1;i+b*o<=m&&j-a*o>=0;o++)
				num++;
			for(o=-1;i+b*o>=0&&j-a*o<=n;o--)
				num++;
		}
	num+=3*n*m;
	cout<<num;
}
