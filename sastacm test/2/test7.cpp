#include<stdio.h>
int main()
{
	 long long int a,b,n,r,i;
	while(scanf("%d %d %d",&a,&b,&n)!=EOF)
	{
		if(n==0)
			printf("%d\n",a);
		if(n==1)
			printf("%d\n",b);
		else if(n!=1&&n!=0)
			{
				for(i=1;i<=n;i++)
					{
						r=b;
						b=a*b%1000000007;
						a=r;
					}
				printf("%d\n",a);
			}
	}
		return 0;
}
