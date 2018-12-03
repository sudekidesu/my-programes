#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x1,y1,x2,y2,x,y,k,a,b,l,d,ans;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);
		x1-=x;
		x2-=x;
		y1-=y;
		y2-=y;
		if(x1==x2)
			ans=x1*(y2-y1)/2;
		else if(y1==y2)
			ans=y1*(x2-x1)/2;
		if(x1==x2||y1==y2)
		{
			printf("%.2lf\n",ans>=0?ans:-ans);
			continue;
		}
		k=(y2-y1)/(x2-x1);
		b=y1-k*x1;
		a=x1-y1/k;
		l=sqrt(pow(b,2)+pow(a,2));
		d=a*b/l;
		ans=d*sqrt(pow(y2-y1,2)+pow(x2-x1,2))/2;
		if(y2/y1==x2/x1)
			ans=0;
		printf("%.2lf\n",ans>=0?ans:-ans);
	}
}
