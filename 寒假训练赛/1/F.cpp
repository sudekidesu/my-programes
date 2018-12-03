#include<cstdio>
int main()
{
	int a,b,c,t,s,h;
	scanf("%d",&t);
	for(s=0;s<t;s++)
	{
		h=100;
		scanf("%d %d %d",&a,&b,&c);
		for(;b>=0;b--)
		{
			h-=a;
			if(h<=0)
			{
				printf("NO\n");
				break;
			}
			if(h-6*a<=0&&c>0)
			{
				c--;
				h=80;
			}
		}
		if(h>0)
			printf("YES\n");
	}
 } 
