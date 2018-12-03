#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct tree
{
  int left,right;
  long long n;
}t[3000000];
int num[1000005];
int b[1000005];
int temp[1000005];
long long sum;
void push_up(int k)
{
  t[k].n=t[k<<1].n+t[k<<1|1].n;
}
void make(int l,int r,int k)
{
  if(l==r)
  {
    t[k].left=t[k].right=l;
    t[k].n=num[l];
    b[l]=k;
    return;
  }
  t[k].left=l;
  t[k].right=r;
  make(l,(l+r)>>1,k<<1);
  make(((l+r)>>1)+1,r,k<<1|1);
  push_up(k);
}
void refresh(int k)
{
  k=k>>1;
  while(k>0)
  {
    push_up(k);
    k=k>>1;
  }
}
void Query(int l,int r,int k)
{
	if(l<=t[k].left&&r>=t[k].right)
	{
		sum+=t[k].n;
		return;
	}
	if(l<=(t[k].left+t[k].right)>>1)
		Query(l,r,k<<1);
	if(r>(t[k].left+t[k].right)>>1)
		Query(l,r,k<<1|1);
}
int main()
{
  int m,n;
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&num[i]);
    temp[i]=num[i];
  }
  make(1,n,1);
  while(m--)
  {
    int T,L,R;
    scanf("%d %d %d",&T,&L,&R);
    if(T==1)
    {
      //for(int i=L;i<R;i++)
        //if(temp[i]>temp[i+1])
          //swap(temp[i],temp[i+1]);
      int mid=(R-L+1)>>1;
      int jud=0;
      int maxl=*max_element(temp+L,temp+L+mid);
      int maxm=max(maxl,temp[L+mid]);
      if(maxm>temp[L+mid])
      {
        jud=1;
        swap(temp[L+mid],maxm);
      }
      for(int i=0;i<mid;i++)
      {
        if(temp[L+i]>temp[L+i+1])
          swap(temp[L+i],temp[L+i+1]);
        if(temp[L+mid+i]>temp[L+mid+i+1])
          swap(temp[L+mid+i],temp[L+mid+i+1]);
      }
      if(jud==1)
        temp[L+mid-1]=maxm;
      for(int i=L+2*mid;i<R;i++)
        if(temp[i]>temp[i+1])
          swap(temp[i],temp[i+1]);
    }
    else
    {
      for(int i=1;i<=n;i++)
        if(num[i]!=temp[i])
        {
          num[i]=temp[i];
          t[b[i]].n=num[i];
          refresh(b[i]);
        }
      sum=0;
      Query(L,R,1);
      printf("%I64d\n",sum);
    }
  }
}
