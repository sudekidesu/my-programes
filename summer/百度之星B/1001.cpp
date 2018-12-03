#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
  int d[200005];
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m,k,i,j,l,num;
    scanf("%d %d %d",&n,&m,&k);
    num=n;
    for(i=0;i<n;i++)
      d[i]=0;
    for(l=0;l<m;l++)
    {
      scanf("%d %d",&i,&j);
      num--;
      d[i]++;
      d[j]++;
    }
    int maxm=*max_element(d,d+n);
    printf("%d\n",min(m,maxm+k)+num-1);
  }
}
