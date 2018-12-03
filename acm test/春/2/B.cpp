#include<cstdio>
int main()
{
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<k;i++)
		for(j=i+1;j<=k;j++)
			if(n%i==n%j)
			{
				printf("No");
				return 0; 
			}
	printf("Yes");
}
