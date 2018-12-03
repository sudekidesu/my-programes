#include<cstdio>
#include<cmath>
int a[2187][2187]={0};
int main()
{
	a[1093][0]=1;
	int c,t,n,i,j,jx=1093,m,k,s;
	for(c=0;c<6;c++)
	{
		m=pow(3,c);
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				a[jx-m+i][m+j]=a[jx+i][j];
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				a[jx+i][2*m+j]=a[jx+i][j];
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				a[jx+m+i][m+j]=a[jx+i][j];
		jx-=m;
	}
	scanf("%d",&t);
	for(c=0;c<t;c++)
	{
		m=0;
		scanf("%d",&n);
		s=pow(3,n);
		for(i=1093-(s-1)/2;i<=1093+(s-1)/2;i++)
		{
			for(j=0;j<s;j++)
			{
				if(!a[i][j])
					m++;
				if(a[i][j])
				{
					for(k=0;k<m;k++)
						printf(" ");
					printf("O");
					m=0;
				}
			}
			printf("\n");
			m=0;
		}
	}
	return 0;
 } 
