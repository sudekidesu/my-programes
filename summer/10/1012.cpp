#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int flo[205][205];
int maxx[205];
int maxm=0;
int n,m,k,W;
struct pian
{
  int begin,end,w,op;
}p[205];
void dfs(int kf,int k,int w)
{
  w+=p[k].w;
  if(p[k].op==p[kf].op)
    w-=W;
  if(w>=maxx[k])
    maxx[k]=w;
  for(int i=0;i<m;i++)
    if(flo[k][i])
      dfs(k,i,w);
}
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
      maxx[i]=p[i].w;
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
      {
        flo[i][j]=0;
        if(p[i].end<=p[j].begin)
          flo[i][j]=1;
      }
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(flo[i][j]==1)
          dfs(i,j,maxx[i]);
    printf("%d\n",(*max_element(maxx,maxx+m))*k);
  }
}
