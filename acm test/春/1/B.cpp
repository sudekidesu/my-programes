#include<cstdio>
#include<cstring>
char W[10000],T[1000000];
int main()
{
	int o,t,i,j,m,n,num;
	scanf("%d",&t);
	for(o=0;o<t;o++)
	{
		num=0;
		scanf("%s",W);
		scanf("%s",T);
		m=strlen(W);
		n=strlen(T);
		for(i=0;i<=n-m;i++)
		{
			if(T[i]==W[0])
			{
				for(j=0;j<m;j++)
				{
					if(T[i+j]!=W[j])
						break;
					if(j==m-1)
						num++;
				}
			}
		}
		printf("%d\n",num);
	}
}
