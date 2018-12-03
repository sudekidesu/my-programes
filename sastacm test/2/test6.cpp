#include<stdio.h>
//#include<time.h>
int ifprime(int a)
{
	if(a==1||a==0)
		return 0;
	if(a==2)
		return 1;	
	int b=1 ;
		while(b*b<=a)
		{
			b++;
			if(a%b==0)
				return 0;
			if(a<=b*b)
				return 1;
		}
}
int main()
{
		int t,s,i,L,R,k,n=0;
//		double time;
		scanf("%d",&t);
		for(i=1;i<=t;i++)
			{
				scanf("%d %d",&L,&R);
			//	time=(double)clock()/CLOCKS_PER_SEC*1000;
				for(k=L;k<=R;k++)
				{
					if(ifprime(k))
					{
						s=k%10+k%100/10+k%1000/100+k%10000/1000+k%100000/10000+k%1000000/100000;
						if(ifprime(s))
							n++;
					}
				}
		printf("Case #%d: %d\n",i,n);
		n=0;
		//printf("time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC*1000-time);
			}	
}
