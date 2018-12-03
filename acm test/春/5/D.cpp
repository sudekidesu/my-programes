#include<cstdio>
int main()
{
	int i,j,E,F,P[500],W[500],T,o,N,tempi,num[500],w1,w2,w,jud;
	double q[500],tempd;
	scanf("%d",&T);
	for(o=0;o<T;o++)
	{
		int sum=0;
		scanf("%d %d",&w1,&w2);
		w=w2-w1;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&P[i],&W[i]);
			q[i]=P[i]*1.0/W[i];
		}
		for(i=0;i<N-1;i++)
			for(j=i+1;j<N;j++)
				if(q[i]>q[j])
				{
					tempi=P[i];
					P[i]=P[j];
					P[j]=tempi;
					tempi=W[i];
					W[i]=W[j];
					W[j]=tempi;
					tempd=q[i];
					q[i]=q[j];
					q[j]=tempd;
				}
		for(i=0;i<N;i++)
		{
			num[i]=w/W[i];
			w%=W[i];
			if(w==0)
				break;
		}
		jud=0;
		if(w!=0)
			for(i=0;i<N-1;i++)
			{
				for(j=i+1;j<N;j++)
					if(W[i]+w==W[j]&&num[i]>0)
					{
						num[i]--;
						num[j]++;
						w+=num[j]-num[i];
						jud=1;
						break;
					}
					if(jud==1)
						break;
			}
		for(i=0;i<N;i++)
			sum+=num[i]*P[i];
		if(w==0)
			printf("The minimum amount of money in the piggy-bank is %d.\n",sum);
		else
			printf("This is impossible.\n");
	}
}
