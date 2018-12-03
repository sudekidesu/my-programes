#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  int num[50005];
  int x[50005];
  int maxx,minn;
  int T,o;
  cin>>T;
  for(o=1;o<=T;o++)
  {
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
      cin>>num[i];
    maxx=num[0];
    minn=num[0];
    x[0]=num[0];
    for(i=1;i<n;i++)
    {
      x[i]=num[i]^x[i-1];
      if(x[i]>maxx)
        maxx=x[i];
      if(x[i]<minn)
        minn=x[i];
    }
    int j;
    for(i=0;i<n;i++)
      for(j=0;j<i;j++)
      {
        x[i]^=num[j];
        if(x[i]>maxx)
          maxx=x[i];
        if(x[i]<minn)
          minn=x[i];
      }
    printf("Case %d: %d %d\n",o,maxx,minn);
  }
}
