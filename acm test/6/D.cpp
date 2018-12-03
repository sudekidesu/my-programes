#include<cstdio>
int main()
{
	int S[20],N,i,pro=1,j=0,k=0;
	while(scanf("%d",&N)!=EOF)
	{
		k++;
		j=0;
		pro=1;
		for(i=0;i<N;i++)
			scanf("%d",&S[i]);
		printf("\n");
		for(i=0;i<N;i++)
			if(S[i]>0)
			{
				j++;
				pro*=S[i];
			}
		if(j==0)
			printf("Case #%d: The maximum product is 0.\n\n",k);
		else
			printf("Case #%d: The maximum product is %d.\n\n",k,pro);	
	}
}
