#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,N,k,m,n;
	for(;;)
	{
		n=0;
		scanf("%d",&N);
		if(N==0)
			break;
		for(m=1234;m*N<=98765;m++)
		{
			k=m*N;
			a=m/10000;
			b=m%10000/1000;
			c=m%1000/100;
			d=m%100/10;
			e=m%10;
			if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)
				continue;
			f=k/10000;
			g=k%10000/1000;
			h=k%1000/100;
			i=k%100/10;
			j=k%10;
			if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&a!=h&&a!=i&&a!=j&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i&&b!=j&&c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&c!=i&&c!=j&&d!=e&&d!=f&&d!=g&&d!=h&&d!=i&&d!=j&&e!=f&&e!=g&&e!=h&&e!=i&&e!=j&&f!=g&&f!=h&&f!=i&&f!=j&&g!=h&&g!=i&&g!=j&&h!=i&&h!=j&&i!=j)
			{
				printf("%d%d%d%d%d / %d%d%d%d%d = %d\n",f,g,h,i,j,a,b,c,d,e,N);
				n++;
			}
		}
		if(n==0)
			printf("There are no solutions for %d.\n",N);
		printf("\n");
	}
 } 
