#include<iostream>
#include<cstdio>
using namespace std;
int d[100005];
int ans[100005];
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
      d[i]=i-1;
    for(int i=0;i<m;i++)
    {
      int w;
      scanf("%d",&w);
      ans[i]=d[w];
      for(int j=1;j<=n;j++)
        if(d[j]<ans[i])
          d[j]++;
      d[w]=0;
    }
    for(int i=0;i<m;i++)
    {
      if(i!=0)
        printf(" ");
      printf("%d",ans[i]);
    }
    printf("\n");
  }
}
