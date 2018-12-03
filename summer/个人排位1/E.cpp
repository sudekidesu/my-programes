#include<iostream>
#include<cstdio>
using namespace std;
const int maxm = 100000 + 100;
long long num[maxm];
long long ans;
struct tree
{
	 int left,right;
	 long long n;
}t[2 * maxm + 100];
void make(int l,int r,int k)
{
	if(l==r)
	{
		t[k].left=t[k].right=l;
		t[k].n=num[l];
		return;
	}
	t[k].left=l;
	t[k].right=r;
	make(l,(l+r)/2,2*k);
	make((l+r)/2+1,r,2*k+1);
	t[k].n = t[2*k].n * t[2*k+1].n;
	t[k].n%=1000000009;
}
void multi(int l,int r,int x,int k)
{
	if(t[k].left==t[k].right)
	{
		t[k].n*=x;
		t[k].n%=1000000009;
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		multi(l,r,x,2*k);
	if(r>(t[k].left+t[k].right)/2)
		multi(l,r,x,2*k+1);
	t[k].n = t[2*k].n * t[2*k+1].n;
	t[k].n%=1000000009;
}
void Query(int l,int r,int k)
{
	if(l<=t[k].left&&r>=t[k].right)
	{
		ans*=t[k].n;
		ans%=1000000009;
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		Query(l,r,2*k);
	if(r>=(t[k].left+t[k].right)/2+1)
		Query(l,r,2*k+1);
}
int main()
{
	int n,i,l,r,x;
	char s[1000];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	make(1,n,1);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='m')
		{
			scanf("%d %d %d",&l,&r,&x);
			multi(l,r,x,1);
		}
		else
		{
			scanf("%d %d",&l,&r);
			ans=1;
			Query(l,r,1);
			printf("%I64d\n",ans);
		}
	}
}
