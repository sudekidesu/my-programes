#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
using namespace std;
set<long long> a;
//queue<long long> b;
map<long long,long long> c;
long long g;
void done(long long q,long long w,long long e,long long r,long long t,long long y,long long u,long long i,long long o)
{
	if((w*1000+e*100+r*10+t)%(y*1000+u*100+i*10+o)==0)
	{
		n=q+(w*1000+e*100+r*10+t)/(y*1000+u*100+i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((w*10000+e*1000+r*100+t*10+y)%(u*100+i*10+o)==0)
	{
		n=q+(w*10000+e*1000+r*100+t*10+y)/(u*100+i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((w*100000+e*10000+r*1000+t*100+y*10+u)%(i*10+o)==0)
	{
		n=q+(w*100000+e*10000+r*1000+t*100+y*10+u)/(i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((w*1000000+e*100000+r*10000+t*1000+y*100+u*10+i)%o==0)
	{
		n=q+(w*1000000+e*100000+r*10000+t*1000+y*100+u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((e*1000+r*100+t*10+y)%(u*100+i*10+o)==0)
	{
		n=q*10+w+(w*10000+e*1000+r*100+t*10+y)/(u*100+i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((e*10000+r*1000+t*100+y*10+u)%(i*10+o)==0)
	{
		n=q*10+w+(e*10000+r*1000+t*100+y*10+u)/(i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((e*100000+r*10000+t*1000+y*100+u*10+i)%o==0)
	{
		n=q*10+w+(e*100000+r*10000+t*1000+y*100+u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((r*100+t*10+y)%(u*100+i*10+o)==0)
	{
		n=q*100+w*10+e+(r*100+t*10+y)/(u*100+i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((r*1000+t*100+y*10+u)%(i*10+o)==0)
	{
		n=q*100+w*10+e+(r*1000+t*100+y*10+u)/(i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((r*10000+t*1000+y*100+u*10+i)%o==0)
	{
		n=q*100+w*10+e+(r*10000+t*1000+y*100+u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((t*100+y*10+u)%(i*10+o)==0)
	{
		n=q*1000+w*100+e*10+r+(t*100+y*10+u)/(i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((t*1000+y*100+u*10+i)%o==0)
	{
		n=q*1000+w*100+e*10+r+(t*1000+y*100+u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((y*10+u)%(i*10+o)==0)
	{
		n=q*10000+w*1000+e*100+r*10+t+(y*10+u)/(i*10+o);
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((y*100+u*10+i)%o==0)
	{
		n=q*10000+w*1000+e*100+r*10+t+(y*100+u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if((u*10+i)%o==0)
	{
		n=q*100000+w*10000+e*1000+r*100+t*10+y+(u*10+i)/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
	if(i%o==0)
	{
		n=q*1000000+w*100000+e*10000+r*1000+t*100+y*10+u+i/o;
		if(a.find(n)==a.end())
		{
			a.insert(n);
//			b.push(n);
			c[n]=0;
		}
		c[n]++;
	}
	if(n==100)
		printf("\n%lld%lld%lld%lld%lld%lld%lld%lld%lld %lld\n",q,w,e,r,t,y,u,i,o,c[100]);
}
int main()
{
	long long q,w,e,r,t,y,u,i,o;
	for(q=1;q<=9;q++)
	{
		for(w=1;w<=9;w++)
		{
			if(w==q)
				continue;
			for(e=1;e<=9;e++)
			{
				if(e==q||e==w)
					continue;
				for(r=1;r<=9;r++)
				{
					if(r==q||r==w||r==e)
						continue;
					for(t=1;t<=9;t++)
					{
						if(t==q||t==w||t==e||t==r)
							continue;
						for(y=1;y<=9;y++)
						{
							if(y==1||y==w||y==e||y==r||y==t)
								continue;
							for(u=1;u<=9;u++)
							{
								if(u==q||u==w||u==e||u==r||u==t||u==y)
									continue;
								for(i=1;i<=9;i++)
								{
									if(i==q||i==w||i==e||i==r||i==t||i==y||i==u)
										continue;
									for(o=1;o<=9;o++)
									{
										if(o==q||o==w||o==e||o==r||o==t||o==y||o==u||o==i)
											continue;
										done(q,w,e,r,t,y,u,i,o);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	scanf("%I64d",&n);
	printf("%I64d\n",c[n]);
/*	printf("%d",b.size());
	while(b.size())
	{
		n=b.front();
		printf("%lld %lld\n",n,c[n]);
		b.pop();
		a.erase(n);
	}*/
}
