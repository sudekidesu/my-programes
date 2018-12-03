#include<stdio.h>
int main()
{
	int t,x,j,i,k;
	double y;
	while(scanf("%d",&t)!=EOF)
	{
		k=0;
		for(x=t+1;x<=2*t;x++)
		{
			y=x*t*1.0/(x-t);
			j=y;
			if(y-j==0)
				k++;
		}
		printf("%d\n",k);
		for(x=t+1;x<=2*t;x++)
		{
			y=x*t*1.0/(x-t);
			j=y;
			if(y-j==0)
				printf("1/%d = 1/%d + 1/%d\n",t,j,x);
		}
	}
}
