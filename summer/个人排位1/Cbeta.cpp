#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
	long long x,y;
}p[3];
bool cmp(point a,point b)
{
	if(a.x<b.x)
		return 1;
	else if(a.y<b.y)
		return 1;
	else
		return 0;
}
int main()
{
	int T;
	long long ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y);
		sort(p,p+3,cmp);
		p[1].x-=p[0].x;
		p[2].x-=p[0].x;
		p[1].y-=p[0].y;
		p[2].y-=p[0].y;
		if(p[1].x==p[2].x)
			ans=p[1].x*(p[2].y-p[1].y);
		else if(p[1].y==p[2].y)
			ans=p[1].y*(p[2].x-p[1].x);
		else if(p[2].y*p[1].x>p[1].y*p[2].x)
			ans=p[2].x*p[2].y-p[1].x*p[1].y-(p[2].y+p[1].y)*(p[2].x-p[1].x);
		else
			ans=p[2].x*p[2].y-p[1].x*p[1].y-(p[2].x+p[1].x)*(p[2].y-p[1].y);
		if(ans<0)
			ans=-ans;
		printf("%I64d.%d0\n",ans/2,ans%2?5:0);
	}
}
