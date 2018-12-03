#include<cstdio>
int main()
{
	int n,m,i,j,a,tempi;
	double b,t,tempd;
	int p[10000];
	double q[10000][2];
	for(;;)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			break;
		t=1;
		for(i=0;i<m;i++)
		{
			scanf("%d %lf",&a,&b);
			q[i][0]=b/a;
			q[i][1]=b;
			p[i]=a;
		}
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)
				if(q[i][0]<q[j][0])
				{
					tempd=q[i][0];
					q[i][0]=q[j][0];
					q[j][0]=tempd;
					tempd=q[i][1];
					q[i][1]=q[j][1];
					q[j][1]=tempd;
					tempi=p[i];
					p[i]=p[j];
					p[j]=tempi;
				}
		for(i=0;i<m;i++)
		{
			if(p[i]<=n)
			{
				t*=1-q[i][1];
				n-=p[i];
			}
			if(n==0)
				break;
		}
		printf("%.1f%%\n",(1-t)*100);
	}
	return 0;
}
