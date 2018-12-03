#include<stdio.h>
int prime[80000];
int ifprime[1000000]={1,0};
int main()
{
	extern int prime[80000];
	extern int ifprime[1000000];
	int i,k,j=0,l=0,r,t,s,m,n;
	for(i=2;i<=1000000;i++)
	{
		if(ifprime[i-1]==1)
			continue;
		prime[l]=i;
		l++;
		for(k=1;k*i<=1000000;k++)
			ifprime[k*i-1]=1;
	}
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		n=0;
		scanf("%d %d",&l,&r);
		for(i=l;i<=r;i+=2)
		{	if(i==1)
				i++;
			if(i%2==0&&i!=2)
				i++;
			s=i%10+i%100/10+i%1000/100+i%10000/1000+i%100000/10000+i%1000000/100000;
			for(m=0;prime[m]<=s;m++)
				if(prime[m]==s)
					{
						for(k=0;prime[k]<=i;k++)
							if(prime[k]==i)
							{							
								n++;
								break;
							}
						if(prime[k]==i)
							break;
					}
			if(i==2)
				i--;
		}
		printf("Case #%d: %d\n",j+1,n);
	}
}
