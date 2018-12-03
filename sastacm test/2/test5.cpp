#include<stdio.h>
#include<math.h>
int main()
{
   int n,x,y,c,b,d;
   scanf("%d %d",&x,&y);
   if(x==0&&y==0)
   		return 0;
   for(n=x;n<=y;n++)
   {
   		d=0;
   		c=pow(n,2)+n+41;
   		
   		b=1;
   		while(b*b<=c)
		{
			b++;
			if(c%b==0)
				{
					d++;
					printf("Sorry\n");
					break;
				}
		}
		if(c%b==0)
				{
					break;
				}
   }
   if(d==0)
		printf("OK\n");
	main();
}
