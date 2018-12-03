#include<stdio.h>
int main()
{
	int a[100][100];
	int i,k,m,n; 
	for(i=0;i<100;i++)
		for(k=0;k<=i;k++)
			{
				a[i][k]=1;
				for(m=1;m<=i;m++)
					a[i][k]*=m;
				for(m=1;m<=k;m++)
					a[i][k]/=m;
				for(m=1;m<=i-k;m++)
					a[i][k]/=m;
			}
	int t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		{
			for(k=0;k<=i;k++)
				printf("%5d",a[i][k]);
			printf("\n");
		}
	return 0;
 } 
