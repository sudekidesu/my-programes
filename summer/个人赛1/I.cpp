#include<iostream>
#include<cstdio>
using namespace std;
char seat[2000][2000];
int main()
{
	int n,m,k,i,j,num=0,s=0;
	scanf("%d %d %d",&n,&m,&k);
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%c",&seat[i][j]);
		getchar();
	}
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<m;j++)
		{
			if(seat[i][j]=='*')
				s=0;
			else if(seat[i][j]=='.')
				s++;
			if(s>=k)
				num++;
		}
	}
	s=0;
	for(j=0;j<m;j++)
	{
		s=0;
		for(i=0;i<n;i++)
		{
			if(seat[i][j]=='*')
				s=0;
			else if(seat[i][j]=='.')
				s++;
			if(s>=k)
				num++;
		}
	}
	if(k==1)
		num/=2;
	cout<<num;
}
