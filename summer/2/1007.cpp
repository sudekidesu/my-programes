#include<iostream>
#include<cstdio>
using namespace std;
struct tree
{
	int left,right,sum;
	double temp;
	tree()
	{
		sum=0;
		temp=0;
	}
}t[2500000];
int b[1100000];
int sum;
void make(int l,int r,int k)
{
	if(l==r)
	{
		t[k].left=t[k].right=l;
		return;
	}
	t[k].left=l;
	t[k].right=r;
	make(l,(l+r)/2,2*k);
	make((l+r)/2+1,r,2*k+1);
}
void Query(int l,int r,int k)
{
	if(l<=t[k].left&&r>=t[k].right)
	{
		sum+=t[k].sum;
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		Query(l,r,2*k);
	if(r>(t[k].left+t[k].right)/2)
		Query(l,r,2*k+1);
}
void Add(int l,int r,int k)
{
	int j;
	if(t[k].left==t[k].right&&l<=t[k].left&&r>=t[k].right)
	{
		t[k].temp+=1.0/b[t[k].right];
		if(t[k].temp>=1)
		{
			j=t[k].temp;
			t[k].temp-=j;
			t[k].sum+=j;
			t[k/2].temp+=j;
		}
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		Add(l,r,2*k);
	if(r>=(t[k].left+t[k].right)/2+1)
		Add(l,r,2*k+1);
	if(t[k].temp>=1)
	{
		j=t[k].temp;
		t[k].temp-=j;
		t[k].sum+=j;
		t[k/2].temp+=j;
	}
}
int main()
{
	int n,m,l,r;
	char s[20];
	scanf("%d %d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	make(1,n,1);
	while(m--)
	{
		scanf("%s %d %d",s,&l,&r);
		if(s[0]=='a')
			Add(l,r,1);
		if(s[0]=='q')
		{
			sum=0;
			Query(l,r,1);
			printf("%d\n",sum);
		}
	}
}
