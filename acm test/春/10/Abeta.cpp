#include<iostream>
#include<cstdio>
using namespace std;
struct tree
{
	int left,right,sum;
}t[140000];
int sd[50005],sum;
void Add(int i,int j,int l)
{
	t[l].sum+=j;
	if(t[l].left==t[l].right)
		return;
	if(i<=t[2*l].right)
		Add(i,j,2*l);
	else
		Add(i,j,2*l+1);
}
void Sub(int i,int j,int l)
{
	t[l].sum-=j;
	if(t[l].left==t[l].right)
		return;
	if(i<=t[2*l].right)
		Sub(i,j,2*l);
	else
		Sub(i,j,2*l+1);
}
void Query(int left,int right,int l)
{
	if(left>t[l].right||right<t[l].left)
		return;
	if(left<=t[l].left&&right>=t[l].right)
	{
		sum+=t[l].sum;
		return;
	}
	Query(left,right,2*l);
	Query(left,right,2*l+1);
}
void make(int left,int right,int i)
{
	if(left==right)
	{
		t[i].left=t[i].right=left;
		t[i].sum=sd[left];
	}
	else
	{
		t[i].left=left;
		t[i].right=right;
		make(left,(left+right)/2,2*i);
		make((left+right)/2+1,right,2*i+1);
		t[i].sum=t[2*i].sum+t[2*i+1].sum;
	}
}
int main()
{
	int T,o=1,n,i,j;
	char s[10];
	cin>>T;
	while(T--)
	{
		cout<<"Case "<<o<<":"<<endl;
		o++;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&sd[i]);
		make(1,n,1);
		while(1)
		{
			scanf("%s",s);
			if(s[0]=='E')
				break;
			scanf("%d %d",&i,&j);
			if(s[0]=='Q')
			{
				sum=0;
				Query(i,j,1);
				printf("%d\n",sum);
			}
			if(s[0]=='A')
				Add(i,j,1);
			if(s[0]=='S')
				Sub(i,j,1);
		}
	}
	return 0;
}
