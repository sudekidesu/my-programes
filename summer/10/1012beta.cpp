#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int way[205][205];
int dp[205];
int in[205];
int n,m,k,W;
struct pian
{
  int begin,end,w,op;
}p[205],pi[205];
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d %d %d %d",&n,&m,&k,&W);
    for(int i=0;i<m;i++)
      scanf("%d %d %d %d",&p[i].begin,&p[i].end,&p[i].w,&p[i].op);
    for(int i=0;i<m;i++)
      in[i]=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
      	if(p[i].end<=p[j].begin)
        {
      		way[i][j]=1;
          in[j]++;
        }
        else
          way[i][j]=0;
    int o=0;
    while(o<m)
      for(int j=0;j<m;j++)
        if(in[j]==0)
        {
          pi[o]=p[j];
          o++;
          for(int i=0;i<m;i++)
            if(way[j][i]==1)
              in[i]--;
        }
    for(int i=0;i<m;i++)
      dp[i]=pi[i].w;
    for(int i=0;i<m;i++)
      for(int j=i-1;j>=0;j--)
        if(pi[j].end<=pi[i].begin)
          dp[i]=max(dp[i],dp[j]+pi[i].w-(pi[i].op==pi[j].op?W:0));
    printf("%d\n",(*max_element(dp,dp+m))*k);
  }
}
