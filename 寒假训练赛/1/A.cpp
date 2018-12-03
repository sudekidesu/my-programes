#include<cstdio>
int gun[1000][1005];
int main()
{
	int m,n,i,j;
	double b[1005]={0},max,k,temp;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&gun[i][0],&gun[i][1]);
			for(j=0;j<gun[i][1];j++)
				scanf("%d",&gun[i][j+2]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %lf",&j,&temp);
			if(b[j]<temp)
				b[j]=temp;
		}
		max=0;
		for(i=0;i<n;i++)
		{
			k=1;	
			for(j=0;j<gun[i][1];j++)
				k+=b[gun[i][j+2]];
			k*=gun[i][0];
			if(max<k)
				max=k;
		}
		printf("%.4f\n",max);
		for(i=0;i<1005;i++)
			b[i]=0;
	}
 } 
