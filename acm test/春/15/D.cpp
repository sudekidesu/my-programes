#include<iostream>
#include<cstdio>
using namespace std;
struct tree
{
	int left,right;
	double sum;
}t[1000000];
double gr[100005];
double sum;
void change(int a,double b,int l)
{
	if(a>t[l].right||a<t[l].left)
		return;
	t[l].sum+=b-gr[a];
	if(left==right)
	{
		t[l].sum=b;
		return;
	}
	change(a,b,2*l);
	change(a,b,2*l+1);
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
		t[i].sum=gr[left];
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
	int i,n,T,j,a,b;
	double k;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%lf",&gr[i]);
	make(1,n,1);
	cin>>T;
	for(i=0;i<T;i++)
	{
		sum=0;
		scanf("%d",&j);
		if(j==1)
		{
			scanf("%d %lf",&a,&k);
			change(a,k,1);
			gr[a]=k;
		}
		else if(j==2)
		{
			scanf("%d %d",&a,&b);
			Query(a,b,1);
			printf("%lf\n",sum/(b-a+1));
		}
	}
	return 0;
}
