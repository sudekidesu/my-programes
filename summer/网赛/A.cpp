#include<iostream>
#include<cstdio>
using namespace std;
int dp[100005][3];
int time[100005][3];
int num[100005][3];
void ddp(int i,int pri)
{
  if()
}
int main()
{
  dp[0][0]=dp[0][1]=dp[0][2]=0;
  time[0][0]=time[0][1]=time[0][2]=0;
  num[0][0]=num[0][1]=num[0][2]=0;
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      int pri;
      scanf("%d",&pri);
      ddp(i,pri);
    }
  }
}
