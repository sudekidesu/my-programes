#include<iostream>
using namespace std;
int min(int a,int b);
int main()
{
	int au[2005][2]={0},K;
	int dp[2005]={0};
	int o,N,i;
	cin>>N;
	for(o=0;o<N;o++)
	{
		int HH=8,MM=0,SS=0;
		cin>>K;
		for(i=1;i<=K;i++)
			cin>>au[i][0];
		for(i=2;i<=K;i++)
			cin>>au[i][1];
		dp[1]=au[1][0];
		for(i=2;i<=K;i++)
			dp[i]=min(dp[i-1]+au[i][0],dp[i-2]+min(au[i][0]+au[i-1][0],au[i][1]));
		SS+=dp[K];
		if(SS>=60)
		{
			MM+=SS/60;
			SS%=60;
		}
		if(MM>=60)
		{
			HH+=MM/60;
			MM%=60;
		}
		if(HH>12)
			printf("%02d:%02d:%02d pm\n",HH-12,MM,SS);
		else
			printf("%02d:%02d:%02d am\n",HH,MM,SS);
	}
 } 
 int min(int a,int b)
{
	return a<b?a:b;
}
