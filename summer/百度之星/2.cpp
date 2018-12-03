#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[200005];
int num;
struct tree
{
	int left,right;
	int n[26];
	tree()
	{
		for(int i=0;i<26;i++)
			n[i]=0;
	}
};
static tree t[400005];
void make(int l,int r,int k)
{
	if(l==r)
	{
		t[k].left=t[k].right=l;
		t[k].n[s[l]-'A']=1;
		return;
	}
	t[k].left=l;
	t[k].right=r;
	make(l,(l+r)/2,2*k);
	make((l+r)/2+1,r,2*k+1);
	for(int i=0;i<26;i++)
		t[k].n[i]=t[2*k].n[i]+t[2*k+1].n[i];
}
void Query(int l,int r,int k,int a)
{
	if(l<=t[k].left&&r>=t[k].right)
	{
		num+=t[k].n[a];
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		Query(l,r,2*k,a);
	if(r>=(t[k].left+t[k].right)/2+1)
		Query(l,r,2*k+1,a);
}
int main()
{
	char a;
	int T,i,n,m,j,k,o;
	scanf("%d",&T);
	for(o=1;o<=T;o++)
	{
		printf("Case #%d:\n",o);
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		make(1,n,1);
		for(i=0;i<m;i++)
		{
			num=0;
			scanf("%d %d",&j,&k);
			a=*min_element(s+j,s+k+1);
			Query(j,k,1,(a-'A'));
			printf("%d\n",num);
		}
	}
 }
