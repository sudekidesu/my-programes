#include<cstdio>
struct ver
{
	int l,r;
	int num;
	ver()
	{
		l=r=-1;
		num=0;
	}
}v[300000];
int ve[300000]={0};
int num=0,d,t;

void search(int k)
{
	ve[k]++;
	if(v[k].num!=2)
		return;
	if(k==d)
	{
		num++;
		return;
	}
	if(v[k].l==t)
	{
		t=k;
		search(v[k].r);
	}
	else
	{
		t=k;
		search(v[k].l);
	}
}
int main()
{
	int n,m,i;
	int x,y;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].num++;
		v[y].num++;
		if(v[x].num<=2&&v[y].num<=2)
		{
			if(v[x].l==-1)
				v[x].l=y;
			else
				v[x].r=y;
			if(v[y].l==-1)
				v[y].l=x;
			else
				v[y].r=x;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ve[i]>0)
			continue;
		if(v[i].num==2)
		{
			d=i;
			t=i;
			search(v[i].r);
		}
	}
	printf("%d",num);
}
