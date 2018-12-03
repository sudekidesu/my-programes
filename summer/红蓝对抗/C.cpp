#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxm = 100000 + 100;
int num[maxm];
int maxx,minn;
int n;
vector<int> a;
vector<int> b;
struct tree
{
	 int left,right;
	 int n;
}t[maxm*2 + 100];
void push_up(int k)
{
		t[k].n = t[k<<1].n^t[k<<1|1].n;
}
void make(int l,int r,int k)
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
			t[k].n=num[l];
			if(t[k].n>maxx)
      			maxx=t[k].n;
   			if(t[k].n<minn)
     			minn=t[k].n;
     		if(t[k].right==((1+n)>>1))
				a.push_back(t[k].n);
			if(t[k].left==((1+n)>>1)+1)
				b.push_back(t[k].n);
			return;
		}
		t[k].left=l;
		t[k].right=r;
		make(l,((l+r)>>1),k<<1);
		make(((l+r)>>1)+1,r,k<<1|1);
		push_up(k);
		if(t[k].right==((1+n)>>1))
			a.push_back(t[k].n);
		if(t[k].left==((1+n)>>1)+1)
			b.push_back(t[k].n);
    if(t[k].n>maxx)
      maxx=t[k].n;
    if(t[k].n<minn)
      minn=t[k].n;
}
int main()
{
  ios::sync_with_stdio(false);
  int T,i,o;
  vector<int>::iterator j,k;
  cin>>T;
  for(o=1;o<=T;o++)
  {
    cin>>n;
    for(i=1;i<=n;i++)
      cin>>num[i];
    maxx=0;
    minn=1000000000;
    make(1,n,1);
    for(j=a.begin();j!=a.end();j++)
    	for(k=b.begin();k!=b.end();k++)
    	{
    		if(((*j)^(*k))>maxx)
    			maxx=((*j)^(*k));
    		if(((*j)^(*k))<minn)
    			minn=((*j)^(*k));
		}
    printf("Case %d: %d %d\n",o,maxx,minn);
  }
}
