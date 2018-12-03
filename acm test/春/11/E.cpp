#include<bits/stdc++.h>
int main()
{
	int T,i;
	int h[3];
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y,a,b;
		h[1]=10000;
		h[0]=-1; 
		scanf("%d %d %d",&n,&x,&y);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a<=x&&b>=y)
				if(a<h[1]||(a==h[1]&&b>h[2]))
				{
					h[0]=i;
					h[1]=a;
					h[2]=b;
				}
		}
		printf("%d\n",h[0]);
	}
}
