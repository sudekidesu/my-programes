#include<stdio.h>
int main()
{
	int a,b,i,k,m;
	int s[110][2];
	int t[105];
	for(;;)
	{
		scanf("%d %d",&a,&b);
		if(a==0&&b==0)
			return 0;
		for(i=0;i<b;i++)
			scanf("%d %d",&s[i][0],&s[i][1]);
		for(i=0;i<105;i++)
			t[i]=i;
		for(i=0;i<=a;i++)
			for(k=0;k<b;k++)
				if(s[k][0]>s[k][1])
					{
						m=t[s[k][0]];
						t[s[k][0]]=t[s[k][1]];
						t[s[k][1]]=m;
					}
		for(i=1;i<a;i++)
			printf("%d ",t[i]);
		printf("%d\n",t[a]);
	}
} 
