#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int num[200005];
int ml[200005];
int mr[200005];
int lm[200005];
int maxl;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    maxl=0;
    int i,l=0;
    for(i=0;i<200005;i++)
      lm[i]=INF;
    int n;
    cin>>n;
    cin>>num[0];
    ml[0]=1;
    for(i=1;i<n;i++)
    {
      cin>>num[i];
      if(num[i]>num[i-1])
        ml[i]=ml[i-1]+1;
      else
        ml[i]=1;
    }
    mr[n-1]=1;
    for(i=n-2;i>=0;i--)
      if(num[i]<num[i+1])
        mr[i]=mr[i+1]+1;
      else
        mr[i]=1;
    for(i=0;i<n;i++)
    {
      int left=0,right=l,ans=-1,mid;
      while(left<=right)
      {
        mid=left+right>>1;
        if(lm[mid]<num[i])
        {
          ans=mid;
          left=mid+1;
        }
        else
          right=mid-1;
      }
      maxl=max(maxl,mr[i]+ans);
      if(ml[i]>l)
        l=ml[i];
      lm[ml[i]]=min(lm[ml[i]],num[i]);
    }
    cout<<maxl<<endl;
  }
}
