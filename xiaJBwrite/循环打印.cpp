#include<stdio.h>
int main()
{
	int a,b,c;
	b=1;
	printf("����һ�����������ְ�\n");
	scanf("%d",&c);
	do
	{
		a=0;
		while(a<b)
		{
			printf("#");
			a=a+1;
		}
	b=b+1;
	printf("\n");
	}while(b<=c);
	getchar();
	return 0;
 }
