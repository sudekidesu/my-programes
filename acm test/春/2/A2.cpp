#include<cstdio>
int main()
{
	int a=0,b=0,c=0,n,num=0;
	scanf("%d",&n);
	for(a=2;a<=n;a++)
	{
		for(b=1;b<=a;b++)
		{
			for(c=a-b+1;c<=b;c++)
				if(!(a^b^c))
					num++;
		}
	}
	printf("%d",num);
 }
