#include<stdio.h>
int main()
{
	int a,b,c=10000000,d=1; 
//	printf("2       ");
	for(a=3;a<=c;a+=2)
	{
		for(b=1;b*b<=a;)
		{
			b++;
			if(a%b==0)
				break;
			if(a<=b*b)
			{
//				printf("%-8d",a);
				d++;
//				if(d%10==0)
//					printf("\n");
			}
		}
	}
	printf("\nǰ%d����Ȼ���й���%d������",c,d);
	return 0;
}
