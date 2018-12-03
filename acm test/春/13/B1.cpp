#include<iostream>
using namespace std;
struct card
{
	int t;
	int r,l;
	int a;
}c[1005],temp;
int main()
{
	int x=1,y=1,c1,c2,i,j,n,k1=0,k2=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>c[i].t>>c[i].r>>c[i].l;
		c[i].a=c[i].r-c[i].l;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(c[i].t<c[j].t)
		{
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
		}
	for(k1=k2;c[k2].t==c[k1].t;k2++);
	for(i=k1;i<k2-2;i++)
		for(j=i+1;j<k2-1;j++)
		if(c[i].a<c[j].a)
		{
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
		}
	for(i=k2;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(c[i].a<c[j].a)
		{
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
		}
	k2=0;
	for(;k2<n;)
	{
		for(k1=k2;c[k2].a==c[k1].a;k2++)
			if(k2>=n)
				break;
		for(i=k1;i<k2-2;i++)
		for(j=i+1;j<k2-1;j++)
		if(c[i].a<c[j].a)
		{
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		if(c[i].t==1)
			x+=c[i].a;
		if(c[i].t==2)
			y+=c[i].a;
		if(x<=0||y<=0)
		{
			cout<<"N0"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	cout<<"("<<x<<", "<<y<<")"<<endl;
}
