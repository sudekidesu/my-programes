#include<iostream>
#include<cstdio>
using namespace std;
int mo[200005]={0};
int dead[200005]={0};
int DNA[200005]={0};
int main()
{
  freopen("eve.in","r",stdin);
  freopen("eve.out","w",stdout);
  int n;
  char t[2];
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%s",t);
    mo[i]=i;
  }
  n++;
  int m;
  scanf("%d",&m);
  while(m--)
  {
    int a,b;
    scanf("%d",&a);
    if(a>0)
    {
      scanf("%d %s",&b,t);
      while(mo[b]!=b)
        b=mo[b];
      mo[n]=b;
      n++;
    }
    else
      dead[-a]=1;
  }
  n--;
  scanf("%d",&m);
  while(m--)
  {
    int a,b;
    scanf("%d %d",&a,&b);
    DNA[mo[a]]=b;
  }
  int cnt1=0,cnt2=0,cnt3=0;
  int temp1=-1,temp2=-1;
  for(int i=1;i<=n;i++)
    if(dead[i]!=1)
    {
      if(mo[i]!=temp1)
      {
        temp1=mo[i];
        cnt1++;
      }
      if(DNA[mo[i]]!=temp2&&DNA[mo[i]]!=0)
      {
        temp2=DNA[mo[i]];
        cnt2++;
      }
      if(DNA[mo[i]]==0)
        cnt3++;
    }
  if(cnt1==1||(cnt2==1&&cnt3==0))
    printf("YES\n");
  else if(cnt2<=1&&cnt3>0)
    printf("POSSIBLY\n");
  else
    printf("NO\n");
}
