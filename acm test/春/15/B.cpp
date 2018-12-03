#include<iostream>
#include<cstdio>
using namespace std;
int dp[1000005];
struct monos
{
	char name[15];
	int weight;
}mono[1005];
struct bags
{
	bool t[1005];
}bag[100005];
bags g;
int main()
{
	int w,n,m,i,j,k,wm,sum=0,a,b,s;
	int weight[1005];
	cin>>w>>n;
	for(i=0;i<n;i++)
	{
		scanf("%s %d",mono[i].name,&mono[i].weight);
		sum+=mono[i].weight;
	}
	for(i=0;i<1005;i++)
		g.t[i]=true;
	cin>>m;
	for(i=0;i<m;i++)
		scanf("%d",&weight[i]);
	for(k=0;k<m;k++)
	{
		wm=sum+w-(weight[k]+1)/2;
		if((weight[k]+1)/2<=w)
		{
			printf("0\n");
			continue;
		}
		if((weight[k]+1)/2>w+sum)
		{
			printf("-1\n");
			continue;
		}
		for(j=0;j<=wm;j++)
		{
			dp[j]=0;
			bag[j]=g;
		}
		for(i=0;i<n;i++)
			for(j=wm;j>=mono[i].weight;j--)
				if(mono[i].weight<=wm)
				{
					a=dp[j];
					b=dp[j-mono[i].weight]+mono[i].weight;
					if(a<b)
					{
						bag[j]=bag[j-mono[i].weight];
						bag[j].t[i]=false;
						dp[j]=b;
					}
				}
		s=0;
		for(i=0;i<n;i++)
			if(bag[wm].t[i]==true)
				s++;
		cout<<s;
		for(i=0;i<n;i++)
			if(bag[wm].t[i]==true)
				printf(" %s",mono[i].name);
		printf("\n");
	}
}
