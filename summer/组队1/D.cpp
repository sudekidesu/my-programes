#include<iostream>
#include<cstdio>
using namespace std;
struct number
{
  int ll,rl;
  int n;
}d[200005];
int maxl=0;
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--)
  {
    maxl=0;
    int n;
    cin>>n;
    int i,j;
    cin>>d[0].n;
    d[0].ll=1;
    for(i=1;i<n;i++)
    {
      cin>>d[i].n;
      if(d[i].n>d[i-1].n)
        d[i].ll=d[i-1].ll+1;
      else
        d[i].ll=1;
    }
    d[n-1].rl=1;
    for(i=n-2;i>=0;i--)
      if(d[i].n<d[i+1].n)
        d[i].rl=d[i+1].rl+1;
      else
        d[i].rl=1;
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
        if(d[i].n<d[j].n&&d[i].ll+d[j].rl>maxl)
          maxl=d[i].ll+d[j].rl;
    printf("%d\n",maxl);
  }
}
