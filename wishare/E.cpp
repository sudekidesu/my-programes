#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j,p,q,x=-1,y=-1,x0,y0,d,l=0;
	char a[101],b[101];
	cin>>m>>n>>a>>b;
	for(i=x+1;i<m;i=x+1)
	{
		d=n-y;
		x0=x;
		y0=y;
		for(p=1;p+x0<=m&&p<d;p++)
			for(q=1;q<d;q++)
				if(a[x0+p]==b[y0+q]&&q+p<=d)
				{
					d=p+q;
					x=x0+p;
					y=y0+q;
					break;
				}
		if(x!=i-1)
			l++;
		else
			x++;
	}
	cout<<m+n-2*l;
}
