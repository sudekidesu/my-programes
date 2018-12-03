#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int maxx[2];
int road[500][500]={0};
int e[500][500];
int n,m;
void findway(int t)
{
	int i,j;
	for(i=0;i<500;i++)
		for(j=0;j<500;j++)
			if(road[i][j]==t)
				e[i][j]=1;
			else
				e[i][j]=999999999;
	int k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);
}
int main()
{
	cin>>n>>m;
	int i,j,k;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&j,&k);
		road[k][j]=road[j][k]=1;
	}
	if(road[1][n]==0)
	{
		findway(1);
		maxx[1]=e[1][n];
		maxx[0]=1;
	}
	else
	{
		findway(0);
		maxx[0]=e[1][n];
		maxx[1]=1;
	}
	if(maxx[0]>=100000||maxx[1]>=100000)
		maxx[0]=maxx[1]=-1;
	printf("%d",maxx[0]>maxx[1]?maxx[0]:maxx[1]);
}
