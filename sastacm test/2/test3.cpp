#include<stdio.h>
int main()
{
	int a,b,c=1,i;
	scanf("%d %d",&a,&b);
	if(a==0&&b==0)
		return 0;
	for(i=0;i<b;i++)
		{
			c*=a;
			c%=1000;
		}
	printf("%d\n",c);
	main();
 } 
