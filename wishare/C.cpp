#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T,time,Time,o,i,j,k,N,huo[105],m,n,num;
	int dp[10005];
	cin>>T;
	for(o=0;o<T;o++)
	{
		time=0;
		cin>>N;
		num=0;
		for(i=1;i<=N;i++)
		{
			cin>>m>>n;
			for(k=0;k<n;k++)
			{
				huo[num]=m;
				num++;
			}
			time+=m*n;
		}
		Time=time/2;
		for(i=0;i<=Time;i++)
			dp[i]=0;
		j=0;
		for(i=0;i<num;i++)
			if(huo[i]<=Time)
				for(j=Time;j>=huo[i];j--)
					dp[j]=max(dp[j-huo[i]]+huo[i],dp[j]);
		cout<<time-dp[Time]<<endl;
	}
	return 0;
}
