#include<iostream>
using namespace std;
bool teki[40001][40001]={false};
int search(int m,int n,int W,int H);
int main()
{
	int i,j,N,W,H,x,y,num,nummax,xmax,xmin,ymax,ymin,imax,jmax;
	for(;;)
	{
		num=0;
		nummax=0;
		cin>>N;
		if(N==-1)
			break;
		cin>>W>>H;
		for(i=0;i<N;i++)
		{
			cin>>x>>y;
			if(x<xmin)
				xmin=x;
			if(x>xmax)
				xmax=x;
			if(y<ymin)
				ymin=y;
			if(y>ymax)
				ymax=y;
			teki[x+20000][y+20000]=true;
		}
		i=xmin;
		if(xmin>40001-W)
			i=40001-W;
		j=ymin;
		if(ymin>40001-H)
			j=40001-H;
		if(xmax<=40001-W)
			imax=xmax+20000;
		else
			imax=40001-W;
		if(ymax<=40001-H)
			jmax=ymax+20000;
		else
			jmax=40001-H;
		for(;i<=imax;i++)
			for(;j<=jmax;j++)
			{
				num=search(i,j,W,H);
				if(num>nummax)
					num=nummax;
			}
		cout<<nummax<<endl;
	}
}
int search(int m,int n,int W,int H)
{
	int i,j,num1=0;
	for(i=0;i<W;i++)
		for(j=0;j<H;j++)
			if(teki[m+i][n+j]==true)
				num1++;
	return num1;
}
