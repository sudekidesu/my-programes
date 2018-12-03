#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int M[100][100]={0};
	int A[10];
	int T,L,i,j;
	int x1,x2,y1,y2;
	long long nx,ny;
	int n;
	long long sum=0,sumx,sumy;
	long long sum1=0;
	scanf("%d",&T);
	while(T--)
	{
		sum1=0; 
		scanf("%d",&L);
		for(i=0;i<L;i++)
			scanf("%d",&A[i]);
		int cursor = 0;
		for (i = 0;i<100; ++i) 
		{
    		for (j = 0; j <= i; ++j)
			{ 
     		   	M[j][i - j] = A[cursor];
        		cursor = (cursor + 1) % L;
    		}
		}
		for(i=0;i<2*L;i++)
			for(j=0;j<2*L;j++)
				sum1+=M[i][j];
		scanf("%d",&n);
		int l2=2*L;
		while(n--)
		{
			sum=sumx=sumy=0;
			nx=ny=0;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(y2-y1>l2)
			{
				ny=y2/l2-y1/l2-1;
				y2-=l2*ny;
			}
			if(x2-x1>l2)
			{
				nx=x2/l2-x1/l2-1;
				x2-=l2*nx;
				for(i=0;i<l2;i++)
					for(j=y1;j<=y2;j++)
						sumx+=M[i%l2][j%l2];
				sum+=nx*sumx;
			}
			if(ny>0)
			{
				for(i=x1;i<=x2;i++)
					for(j=0;j<l2;j++)
						sumy+=M[i%l2][j%l2];
				sum+=ny*sumy;
			}
			sum+=ny*nx*sum1;
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++)
					sum+=M[i%l2][j%l2];
			printf("%lld\n",sum);
		}
	}
}
