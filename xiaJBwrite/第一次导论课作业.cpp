#include<stdio.h>
int main()
{
	int k,sum,i;
	float pi,result;
	printf("月份为：");
	scanf("%d",&k); 
	printf("\n");
	switch(k)
	{
		case 12:
			sum=0;
				for(i=1;i<=99;i++)
			{
				sum+=i;
			}
			printf("%d",sum);
			break;
		case 11:
			pi=3.1415926;
			result=pi*pi;
			printf("%.4f",result);
			break;
		case 10:
			printf("2是00000010\n-2是10000010\n他们的补码之和为10000000");
			
	}
	return 0;
 } 
