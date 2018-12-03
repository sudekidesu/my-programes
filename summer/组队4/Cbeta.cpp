#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
set<int> num[100005];
int inp[200005];
int ans[200005];
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
      inp[i]=n-i;
    for(int i=n;i<n+m;i++)
      scanf("%d",&inp[i]);
    for(int i=0;i<n+m;i++)
    {
      ans[i]=num[inp[i]].size();
      num[inp[i]].clear();
    }
    for(int i=n;i<n+m;i++)
    {
      if(i!=n)
        printf(" ");
      printf("%d",ans[i]);
    }
    printf("\n");
  }
}
