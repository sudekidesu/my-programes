#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	if(a==1)
	{
		printf("不是质数\n");
		return 0;
	}
	for(b=2;b<=a;b++)
	{
		if(a%b==0&&a!=b)
		{
			printf("不是质数\n");
			break;
		}
		if(a==b)
		{
			printf("是质数\n");
		}
	}
	return 0;
}
