#include<stdio.h>
#include<math.h>
#include<memory.h>
int j[1048577]={0};
int main()
{
	int u,T;
	while(scanf("%d",&T)!=EOF)
	{
		if(T==-1)
			break;
		for(u=0;u<T;u++)
		{
			int a,b,i,t,k=1;
			scanf("%d %d",&a,&b);
			for(t=0;t<b;t++)
			{
				k=1;
				for(i=1;i<a;i++)
				{
					if(j[k]==0)
					{
						j[k]=1;
						k=k*2;
					}
					else
					{
						j[k]=0;
						k=k*2+1;
					}
				}
			}
			memset(j,0,sizeof(j));
			printf("%d\n",k);
		}
	}
 } 
