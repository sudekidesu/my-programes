#include<iostream>
#include<cstdio>
using namespace std;
char seat[2000][2000];
int count(int n,int m,int k)
{
	int i,j,num=0;
	for(i=n;i>=0&&n-i<=k;i--)
		if(seat[i][m]=='*')
			break;
		else if(n-i==k)
			num++;
	for(i=m;i>=0&&m-i<=k;i--)
		if(seat[n][i]=='*')
			break;
		else if(m-i==k)
			num++;
	return num;
}
int main()
{
	int n,m,k,i,j,num=0;
	scanf("&d &d &d",&n,&m,&k);
	k--;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%c",&seat[i][j]);
			num+=count(i,j,k);
		}
	cout<<num;
}
