#include<iostream>
#include<cstdio>
using namespace std;
int max1=10000,max2=10000;
int t=0;
int road[500][500]={0};
int town[500]={0};
int n,m;
void findway1(int k)
{
	int i;
	if(town[k]==1)
	{
		t--;
		return;
	}
	town[k]=1;
	if(road[k][n]==1)
	{
		t++;
		if(t<max1)
			max1=t;
		town[k]=0;
		return;
	}
	else
		for(i=1;i<=n;i++)
		{
			if(i==k)
				continue;
			else if(road[k][i]==1)
			{
				t++;
				findway1(i);
			}
		}
	town[k]=0;
}
void findway2(int k)
{
	int i;
	if(town[k]==1)
	{
		t--;
		return;
	}
	town[k]=1;
	if(road[k][n]==0)
	{
		t++;
		if(t<max2)
			max2=t;
		town[k]=0;
		return;
	}
	else
		for(i=1;i<=n;i++)
		{
			if(i==k)
				continue;
			else if(road[k][i]==0)
			{
				t++;
				findway2(i);
			}
		}
	town[k]=0;
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
	t=0;
	if(road[1][n]==0)
	{
		max2=1;
		findway1(1);
	}
	else
	{
		max1=0;
		findway2(1);
	}
	if(max1==10000||max2==10000)
		max1=max2=-1;
	printf("%d",max1>max2?max1:max2);
}
