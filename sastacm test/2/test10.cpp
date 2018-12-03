#include<stdio.h>
int main()
{
	int n,i,a,b,sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a<b)
		{
			a=a^b;
			b=b^a;
			a=a^b;
		}
		sum=2*a+b;
		printf("%d\n",sum);
	}
}
