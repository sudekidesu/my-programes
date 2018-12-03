#include<cstdio>
int main()
{
	int i,j,m,n,T;
	scanf("%d",&T);
	while(T--)
	{
		int sum=0;
		scanf("%d %d",&m,&n);
		if(m<0)
			m=-m;
		if(n<0)
			n=-n;
		for(i=-150;i<=150;i++)
			for(j=-150;j<=150;j++)
				if((i!=0||j!=0)&&(m*i+n*j)%(i*i+j*j)==0&&(m*j-n*i)%(i*i+j*j)==0)
					sum++;
		if(sum<=8)
			printf("P\n");
		else
			printf("C\n");
	}
}
