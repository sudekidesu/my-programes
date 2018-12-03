#include<stdio.h>
int main()
{
	int n,T,i,k,sum=0,A,B;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(k=0;k<n;k++)
			{
				scanf("%d %d",&A,&B);
				sum+=A*B;
			}
		printf("%d\n",sum);
		sum=0;
	}
}
