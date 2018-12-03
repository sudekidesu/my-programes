#include<stdio.h>
 int main()
 {
	int T,n,i,m,a,b,k,a1,b1,r;
	int la[10];
	int lb[10];
	scanf("%d",&T);
	for(i=1;i<=T;i++)
		{
			scanf("%d",&n);
			scanf("%d",&la[0]);
			for(m=1;m<n;m++)
				{
					scanf(" %d",&la[m]);
				}
			scanf("%d",&lb[0]);
			for(m=1;m<n;m++)
				{
					scanf("%d",&lb[m]);
				}
			a=la[n-1];
			b=lb[n-1];
			for(m=n-1;m>0;m--)
				{
					k=a;
					a=la[m-1]*a+b;
					b=k*lb[m-1];
				}
			a1=a;
			b1=b;
			do
			{
				r=a1%b1;
				a1=b1;
				b1=r;
			}while(r!=0);
			a=a/a1;
			b=b/a1;
			printf("Case #%d: %d %d\n",i,b,a);
		}
	return 0;
 }
