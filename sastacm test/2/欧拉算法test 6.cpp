#include<stdio.h>
#include<math.h>
long int prime[80000];
int main()
{
	extern long int prime[80000];
	int i,k,b=1,t,l,r,j,n,s,m;
	prime[0]=2;
	for(i=3;i<1000000;i++)
	{
		for(k=0;prime[k]<=sqrt(i);k++)
		{
			if(!(i%prime[k]))
				break;
		}
		if(prime[k]>sqrt(i))
			{
				prime[b]=i;
				b++;
			}
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
