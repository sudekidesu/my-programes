#include<stdio.h>
int main()
{
	int n,i,sum;
	i=1;
	sum=0;
	scanf("%d",&n);
	do
	{
		sum=sum+i;
		i=i+1;
	}while(i<=n);
	printf("%d",sum);
	scanf("%c");
	return 0;
}
