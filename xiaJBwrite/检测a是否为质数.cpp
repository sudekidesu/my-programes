#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	if(a==1)
	{
		printf("��������\n");
		return 0;
	}
	for(b=2;b<=a;b++)
	{
		if(a%b==0&&a!=b)
		{
			printf("��������\n");
			break;
		}
		if(a==b)
		{
			printf("������\n");
		}
	}
	return 0;
}
